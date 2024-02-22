#ifndef __IDGENERATER_H_
#define __IDGENERATER_H_

#include <mutex>
#include <string>
#include <chrono>
#include <thread>
#include <cstdint>
#include <stdexcept>

/*
* 使用示例
*	#include "uselib/snowflake/TestSnowflake.h"
	auto idGen = IDGenerater<NonLockType>::GetInstance(1, 1);//auto=IDGenerater<NonLockType>*
	std::cout << idGen->NextID() << std::endl;
*/

/*
  Twitter雪花算法
 */
 /*-------高位---------------------------------------------共64位---------------------------------------------低位-------|
   |-----------------------------------------------------------------------------------------------------------------------|
   |    0    |    0000000000 0000000000 0000000000 0000000000 0    |         00000        |        00000        |   000000000000    |
   |未使用 |                    41位时间戳                        |    5位DataCenterID    |    5位WorkerID        |    12位序列号        |
   |-----------------------------------------------------------------------------------------------------------------------|
   |未使用 |                    41位时间戳                        |              10位机器ID                |    12位序列号        |
   |----------------------------------------------------------------------------------------------------------------------*/
   //各部分所占大小
constexpr int SEQUENCE_BITS = 12;                //12位序列号，毫秒内计数，一个机器上1毫秒内最多能产生4096个ID
constexpr int WORKER_ID_BITS = 5;
constexpr int DATA_CENTER_ID_BITS = 5;            //5位DataCenterID与5位WorkerID合在一起，是机器ID，共10位，最大能支持1024个节点
constexpr int TIMESTAMP_BITS = 41;                //41位时间戳，能容纳69.7年 ==> (2 ^ 41) / (1000 * 60 * 60* 24 * 365) = 69.7

//各部分偏移                                    根据前一部分所占位宽度决定后一部分偏移量
constexpr int SEQUENCE_ID_SHIFT = 0;
constexpr int WORK_ID_SHIFT = SEQUENCE_BITS;
constexpr int DATA_CENTER_ID_SHIFT = SEQUENCE_BITS + WORKER_ID_BITS;
constexpr int TIMESTAMP_SHIFT = SEQUENCE_BITS + WORKER_ID_BITS + DATA_CENTER_ID_BITS;

//DataCenterID与WorkerID最大取值                根据所占位宽度计算最大值
constexpr std::int64_t MAX_WORKER_ID = (1 << WORKER_ID_BITS) - 1;
constexpr std::int64_t MAX_DATA_CENTER_ID = (1 << DATA_CENTER_ID_BITS) - 1;

//序列号掩码                                    用于控制序列号取值范围
constexpr std::int64_t SEQUENCE_MASK = (1 << SEQUENCE_BITS) - 1;

//时间起点                                        时间戳虽然能容纳69.7年，但如果直接存Unix时间戳(1970.1.1)，最大只能支持到2039年
//                                                所以添加一个比Unix纪元时间晚的开始时间，存相对于开始时间的偏移，那么支持的最大时间则为开始时间 + 69.7年
constexpr std::int64_t START_POINT = 1625068800000LL; //2021.7.1 00:00:00  ==> 41位时间支持到 2090年

//无锁类                                        符合基本可锁定要求，但是不添加锁操作
class NonLockType {
public:
	constexpr void lock() {
	}
	constexpr void unlock() {
	}
};

template<typename LockType = NonLockType>
class IDGenerater final {
public:
	//获取单例
	static IDGenerater* GetInstance(int iDataCenterID = 0, int iWorkerID = 0) {
		if (iDataCenterID < 0 || MAX_DATA_CENTER_ID < iDataCenterID) {
			throw std::invalid_argument(std::string("iDataCenterIDerror"));
		}
		if (iWorkerID < 0 || MAX_WORKER_ID < iWorkerID) {
			throw std::invalid_argument(std::string("iWorkerIDerror"));
		}

		static IDGenerater GeneraterInstance(iDataCenterID, iWorkerID);            //magic static            C++11后静态局部变量初始化已经是线程安全的
		return &GeneraterInstance;
	}
	//生成id
	std::string NextID() {
		std::lock_guard<LockType> lock(m_lock);
		auto i64CurTimeStamp = m_i64BootTimeStamp + GetCurrentTimeStamp<std::chrono::steady_clock>();    //以m_i64BootTimeStamp单调递增时间

		if (i64CurTimeStamp < m_i64LastTimeStamp) {                                //时间回退，睡眠到下一个毫秒再生成
			i64CurTimeStamp = GetNextTimeStampBySleep();

		}
		else if (i64CurTimeStamp == m_i64LastTimeStamp) {                        //一毫秒内生成多个ID
			m_i64SequenceID = (m_i64SequenceID + 1) & SEQUENCE_MASK;            //更新序列号

			if (0 == m_i64SequenceID) {                                            //达到该毫秒能生成的最大ID数量，循环到下一个毫秒再生成
				i64CurTimeStamp = GetNextTimeStampByLoop(i64CurTimeStamp);
			}
		}
		else {                                                                    //新时间，序列号从头开始
			m_i64SequenceID = 0;
		}
		m_i64LastTimeStamp = i64CurTimeStamp;
		return std::to_string(((i64CurTimeStamp - START_POINT) << TIMESTAMP_SHIFT)
			| (m_i64DataCenterID << DATA_CENTER_ID_SHIFT)
			| (m_i64WorkerID << WORK_ID_SHIFT)
			| (m_i64SequenceID << SEQUENCE_ID_SHIFT));
	}

private:
	template<typename ClockType>
	std::int64_t GetCurrentTimeStamp() {
		auto tpTimePoint = std::chrono::time_point_cast<std::chrono::milliseconds>(ClockType::now());    //获取时间并降低精度到毫秒
		return tpTimePoint.time_since_epoch().count();                                                                    //得到时间戳
	}

	std::int64_t GetNextTimeStampByLoop(std::int64_t i64CurTimeStamp) {
		while (i64CurTimeStamp <= m_i64LastTimeStamp)
		{
			i64CurTimeStamp = m_i64BootTimeStamp + GetCurrentTimeStamp<std::chrono::steady_clock>();
		}
		return i64CurTimeStamp;
	}

	std::int64_t GetNextTimeStampBySleep() {
		auto dDuration = std::chrono::milliseconds(m_i64LastTimeStamp);                                                    //时间纪元到现在经历的时间段
		auto tpTime = std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds>(dDuration);            //得到时间点
		std::this_thread::sleep_until(tpTime);
		return m_i64BootTimeStamp + GetCurrentTimeStamp<std::chrono::steady_clock>();
	}

private:
	IDGenerater(int iDataCenterID, int iWorkerID) :m_i64DataCenterID(iDataCenterID), m_i64WorkerID(iWorkerID), m_i64SequenceID(0), m_i64LastTimeStamp(0) {
		m_i64BootTimeStamp = GetCurrentTimeStamp<std::chrono::system_clock>() - GetCurrentTimeStamp<std::chrono::steady_clock>();    //系统开机时间(可能有误，取决于实例化时系统时间)
	}
	IDGenerater() = delete;
	~IDGenerater() = default;

	IDGenerater(const IDGenerater& rhs) = delete;
	IDGenerater(IDGenerater&& rhs) = delete;
	IDGenerater& operator=(const IDGenerater& rhs) = delete;
	IDGenerater& operator=(IDGenerater&& rhs) = delete;

private:
	std::int64_t m_i64DataCenterID;
	std::int64_t m_i64WorkerID;
	std::int64_t m_i64SequenceID;
	std::int64_t m_i64LastTimeStamp;
	std::int64_t m_i64BootTimeStamp;
	LockType m_lock;
};

using NonLockIDGenerater = IDGenerater<>;

#endif    //!__IDGENERATER_H_


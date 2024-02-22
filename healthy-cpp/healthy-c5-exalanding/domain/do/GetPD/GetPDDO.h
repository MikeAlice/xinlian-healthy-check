#pragma once
#ifndef _GETPD_DO_
#define _GETPD_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class GetPDDO
{
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, work_name, Work_name);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	//身份证号
	CC_SYNTHESIZE(uint64_t, id_card, Id_card);
	//联系电话
	CC_SYNTHESIZE(uint64_t, phone, Phone);
public:
	GetPDDO() {
		
	}
};

#endif // !_SAMPLE_DO_
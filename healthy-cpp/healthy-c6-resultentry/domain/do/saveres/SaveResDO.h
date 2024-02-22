#ifndef _SaveRes_DO_
#define _SaveRes_DO_
#include "../DoInclude.h"

/*
* 诊台结果数据库实体类SaveResDO
* 开头小写为DO属性
*/
class SaveResDO
{
	//唯一id
	CC_SYNTHESIZE(string, id,Id);

	//体检人id
	CC_SYNTHESIZE(string, personId, PersonId);
	//科室id
	CC_SYNTHESIZE(string, officeId, OfficeId);
	//科室名称
	CC_SYNTHESIZE(string, officeName, OfficeName);
	//检查医生
	CC_SYNTHESIZE(string, checkDoc, CheckDoc);
	//检查日期
	CC_SYNTHESIZE(string, checkDate, CheckDate);
	// del flag
	CC_SYNTHESIZE(int, delFlag, DelFlag);
	//分组项目id
	CC_SYNTHESIZE(string, groupItemId, GroupItemId);
	//分组项目名称
	CC_SYNTHESIZE(string, groupItemName, GroupItemName);
	//诊断小结
	CC_SYNTHESIZE(string, diagnoseSum, DiagnoseSum);
	//是否复查(0否1是）
	CC_SYNTHESIZE(int, isCheck, IsCheck);
	//createId
	CC_SYNTHESIZE(string, createId, CreateId);
	//createDate
	CC_SYNTHESIZE(string, createDate, CreateDate);
	//updateId
	CC_SYNTHESIZE(string, updateId, UpdateId);
	//updateDate
	CC_SYNTHESIZE(string, updateDate, UpdateDate);

	
	
	// depart res 部分
	//诊断提醒
	CC_SYNTHESIZE(string, diagnoseTip, DiagnoseTip);
	// 检查次数
	CC_SYNTHESIZE(int, check_num, Check_num);
	// 结果状态(0-一般，1-最优)
	CC_SYNTHESIZE(int, state, State);
	// 是否为附件
	CC_SYNTHESIZE(string, isFile, IsFile);


	// item depart res 部分

	// 关联的基础项目id
	CC_SYNTHESIZE(string, orderGroupItemProjectId, OrderGroupItemProjectId);
	// 关联的基础项目名称
	CC_SYNTHESIZE(string, orderGroupItemProjectName, OrderGroupItemProjectName);
	// 体检结果
	CC_SYNTHESIZE(string, result, Result);
	// 计量单位代码
	CC_SYNTHESIZE(string, unitCode, UnitCode);
	// 计量单位名称
	CC_SYNTHESIZE(string, unitName, UnitName);
	// 是否忽略异常（1-否，2-是）
	CC_SYNTHESIZE(int, ignoreStatus, IgnoreStatus);
	// 危急程度
	CC_SYNTHESIZE(string, crisisDegree, CrisisDegree);
	// 阳性
	CC_SYNTHESIZE(int, positive, Positive);
	// depart res 的id
	CC_SYNTHESIZE(string, departResId, DepartResId);
	// 排序num
	CC_SYNTHESIZE(int, orderNum, OrderNum);


public:
	SaveResDO()
		: id(""),
		personId(""),
		officeId(""),
		officeName(""),
		checkDoc(""),
		checkDate(""),
		delFlag(0),
		groupItemId(""),
		groupItemName(""),
		diagnoseSum(""),
		isCheck(0),
		createId(""),
		createDate(""),
		diagnoseTip(""),
		check_num(0),
		state(0),
		isFile(""),
		orderGroupItemProjectId(""),
		orderGroupItemProjectName(""),
		result(""),
		unitCode(""),
		unitName(""),
		ignoreStatus(0),
		crisisDegree(""),
		positive(0),
		departResId(""),
		orderNum(1)
	{
		// 这里将类中的各个成员变量初始化为合适的默认值
		// 如果有其他默认值或者初始化逻辑，请根据实际情况进行修改
	}

};




#endif // !_SaveRes_DO_

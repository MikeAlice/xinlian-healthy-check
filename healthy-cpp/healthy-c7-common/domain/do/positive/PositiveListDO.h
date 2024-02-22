#pragma once
#ifndef _POSITIVE_LIST_DO_
#define _POSITIVE_LIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class PositiveListDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, personName, PersonName);
	// 体检编号
	CC_SYNTHESIZE(string, test_num, Test_Num);
	// 体检科室
	CC_SYNTHESIZE(string, officeName,OfficeName);
	// 体检项目
	CC_SYNTHESIZE(string, order_group_item_project_name, Order_Group_Item_Project_Name);
	// 结果 
	CC_SYNTHESIZE(string, result, Result);
	// 单位
	CC_SYNTHESIZE(string, unit_name, Unit_Name);
	// 参考范围
	CC_SYNTHESIZE(string, scope, Scope);
	// 危机程度
	CC_SYNTHESIZE(string,crisis_degree, Crisis_Degree);
	// 体检日期
	CC_SYNTHESIZE(string, checkDate,CheckDate);
public:
	PositiveListDO() {
	}
};

#endif // !_SAMPLE_DO_
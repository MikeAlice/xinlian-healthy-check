#pragma once
#ifndef _Term_List_DO_
#define _Term_List_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class TermListDO
{
	// 主键
	CC_SYNTHESIZE(string, id, Id);
	// ID
	CC_SYNTHESIZE(string, officeId, OfficeId);
	// 危害因素
	CC_SYNTHESIZE(string, hazardFactorsText, HazardFactorsText);
	// 类型
	CC_SYNTHESIZE(string, inspectType, InspectType);
	//内容
	CC_SYNTHESIZE(string, content, Content);
	//在岗状态
	CC_SYNTHESIZE(string, workStateText, WorkStateText);
public:
	TermListDO() {
		id = "";
		officeId = "";
		hazardFactorsText = "";
		inspectType = "";
		content = "";
		workStateText = "";
	}
};

#endif // !_Term_List_DO_
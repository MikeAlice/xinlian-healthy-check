#pragma once
#ifndef _NAMELIST_DO_
#define _NAMELIST_DO_
#include "../DoInclude.h"

/**
 * 名称列表数据库实体类
 */
class NameListDO
{
	// 签订时间
	CC_SYNTHESIZE(string, signingTime, SigningTime);
	// 委托单位
	CC_SYNTHESIZE(string, groupUnitName, GroupUnitName);
	// 审核状态
	CC_SYNTHESIZE(unsigned int, auditState, AuditState);
public:
	NameListDO() {
		signingTime = "";
		groupUnitName = "";
		auditState = 3;
	}
};

#endif // !_SAMPLE_DO_
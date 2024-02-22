#pragma once
#ifndef _BASEINFO_DO_
#define _BASEINFO_DO_
#include "../DoInclude.h"

/**
 * 名称列表数据库实体类
 */
class BaseInfoDO
{
	// 合同名称
	CC_SYNTHESIZE(string, orderName, OrderName);
	// 合同编号
	CC_SYNTHESIZE(string, orderId, OrderId);
	// 委托单位
	CC_SYNTHESIZE(string, groupUnitName, GroupUnitName);
	// 委托内容
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// 编制部门
	CC_SYNTHESIZE(string, deptName, DeptName);
	// 编制人
	CC_SYNTHESIZE(string, createId, CreateId);
	// 审核人
	CC_SYNTHESIZE(string, auditUserName, AuditUserName);
	// 审核状态
	CC_SYNTHESIZE(string, auditState, AuditState);
	// 联系人
	CC_SYNTHESIZE(string, personName, PersonName);
	// 联系电话
	CC_SYNTHESIZE(string, mobile, Mobile);
	//审核日期
	CC_SYNTHESIZE(string, auditTime, AuditTime);
	// 销售负责人
	CC_SYNTHESIZE(string, salesDirectorName, SalesDirectorName);
	// 签订时间
	CC_SYNTHESIZE(string, signingTime, SigningTime);
	// 交付时间
	CC_SYNTHESIZE(string, dTime, DTime);

public:
	BaseInfoDO() {
		orderName = "";
		orderId = "";
		groupUnitName = "";
		physicalType = "";
		deptName = "";
		createId = "";
		auditUserName = "";
		auditState = "";
		personName = "";
		mobile = "";
		auditTime = "";
		salesDirectorName = "";
		signingTime = "";
		dTime = "";
	}
};

#endif // !_SAMPLE_DO_
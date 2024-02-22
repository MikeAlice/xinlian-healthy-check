#pragma once
#ifndef _BASEINFO_DO_
#define _BASEINFO_DO_
#include "../DoInclude.h"

/**
 * �����б����ݿ�ʵ����
 */
class BaseInfoDO
{
	// ��ͬ����
	CC_SYNTHESIZE(string, orderName, OrderName);
	// ��ͬ���
	CC_SYNTHESIZE(string, orderId, OrderId);
	// ί�е�λ
	CC_SYNTHESIZE(string, groupUnitName, GroupUnitName);
	// ί������
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// ���Ʋ���
	CC_SYNTHESIZE(string, deptName, DeptName);
	// ������
	CC_SYNTHESIZE(string, createId, CreateId);
	// �����
	CC_SYNTHESIZE(string, auditUserName, AuditUserName);
	// ���״̬
	CC_SYNTHESIZE(string, auditState, AuditState);
	// ��ϵ��
	CC_SYNTHESIZE(string, personName, PersonName);
	// ��ϵ�绰
	CC_SYNTHESIZE(string, mobile, Mobile);
	//�������
	CC_SYNTHESIZE(string, auditTime, AuditTime);
	// ���۸�����
	CC_SYNTHESIZE(string, salesDirectorName, SalesDirectorName);
	// ǩ��ʱ��
	CC_SYNTHESIZE(string, signingTime, SigningTime);
	// ����ʱ��
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
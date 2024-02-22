#pragma once
#ifndef _PREVIEWREPORT_DO_
#define _PREVIEWREPORT_DO_
#include "../DoInclude.h"

/**
 * ����Ԥ�����ݿ�ʵ����
 * �����ˣ�С��
 */
class PreviewReportDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(uint32_t, age, Age);
	// ���֤��
	CC_SYNTHESIZE(string, idCard, IdCard);
	// ��ϵ�绰
	CC_SYNTHESIZE(string, mobile, Mobile);
	// �������
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// ������λ
	CC_SYNTHESIZE(string, dept, Dept);
	// ����
	CC_SYNTHESIZE(string, conclusion, Conclusion);
	// �������
	CC_SYNTHESIZE(string, handleOpinion, HandleOpinion);
	// ����ҽ��
	CC_SYNTHESIZE(string, inspectionDoctor, InspectionDoctor);
	// �������
	CC_SYNTHESIZE(string, inspectionDate, InspectionDate);
	// ��쵥λ
	 CC_SYNTHESIZE(string, diagnosticUnit, DiagnosticUnit);
	// PDF��ַ
	CC_SYNTHESIZE(string, href, Href);


public:
	PreviewReportDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
		idCard = "";
		mobile = "";
		physicalType = "";
		dept = "";
		conclusion = "";
		handleOpinion = "";
		inspectionDoctor = "";
		inspectionDate = "";
		diagnosticUnit = "";
		href = "";
	}
};

#endif // !_PREVIEWREPORT_DO_

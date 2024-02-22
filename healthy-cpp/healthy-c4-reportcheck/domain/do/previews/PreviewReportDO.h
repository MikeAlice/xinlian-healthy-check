#pragma once
#ifndef _PREVIEWREPORT_DO_
#define _PREVIEWREPORT_DO_
#include "../DoInclude.h"

/**
 * ����������ݿ�ʵ����
 * ������Z
 */
class PreviewReportDO
{
	// Ψһ���
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, person_name, Person_name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// ���֤��
	CC_SYNTHESIZE(string, id_card, Id_card);
	// ��ϵ�绰
	CC_SYNTHESIZE(string, mobile, Mobile);
	// �������
	CC_SYNTHESIZE(string, physical_type, Physical_type);
	// ������λ
	CC_SYNTHESIZE(string, dept, Dept);
	// �ܼ�����
	CC_SYNTHESIZE(string, inspection_date, Inspection_date);
	// ����������
	CC_SYNTHESIZE(string, conclusion, Conclusion);
	// �������
	CC_SYNTHESIZE(string, handle_opinion, Handle_opinion);
	// ����ҽʦ
	CC_SYNTHESIZE(string, inspection_doctor, Inspection_doctor);
	// ��鵥λ
	CC_SYNTHESIZE(string, diagnostic_unit, Diagnostic_unit);
public:
	PreviewReportDO() {
		id = "";
		person_name = "";
		sex = "";
		age = -1;
		id_card = "";
		mobile = "";
		physical_type = "";
		dept = "";
		conclusion = "";
		handle_opinion = "";
		inspection_doctor = "";
		inspection_date = "";
		diagnostic_unit = "";
	}
};

#endif // !_PREVIEWREPORT_DO_

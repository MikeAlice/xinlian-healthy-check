#pragma once;

#ifndef _REPORT_LIST_DO_
#define _REPORT_LIST_DO_
#include "../DoInclude.h"

/**
 * �����б����ݿ�ʵ����
 */
class ReportListDO
{
	// �����
	CC_SYNTHESIZE(string, test_num, Test_num);
	// ���֤��
	CC_SYNTHESIZE(string, id_card, Id_card);
	// ����
	CC_SYNTHESIZE(string, person_name, Person_name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// �������
	CC_SYNTHESIZE(string, check_date, Check_date);
	// �Ƿ�ϸ�
	CC_SYNTHESIZE(string, check_result, Check_result);
	// ��쵥λ
	CC_SYNTHESIZE(string, physical_unit, Physical_unit);
	// ���״̬
	CC_SYNTHESIZE(int, statu, Statu);
public:
	ReportListDO() {
		test_num = "";
		id_card = "";
		person_name = "";
		sex = "";
		age = 0;
		check_date = "";
		check_result = "";
		physical_unit = "";
		statu = 0;
	}
};
#endif
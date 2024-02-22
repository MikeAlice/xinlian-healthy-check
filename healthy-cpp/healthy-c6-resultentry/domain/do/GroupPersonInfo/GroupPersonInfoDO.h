#pragma once
#ifndef _GROUP_PERSON_INFO_DO_
#define _GROUP_PERSON_INFO_DO_
#include "../DoInclude.h"

class GroupPersonInfoDO
{

	//�Ƿ�ͨ�����
	CC_SYNTHESIZE(int, is_pass, Is_pass);

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
	CC_SYNTHESIZE(string, physical_type, Physical_type);

	// ��������
	CC_SYNTHESIZE(int, sporadic_physical, Sporadic_physical);

	// ��λ����
	CC_SYNTHESIZE(string, dept, Dept);

	// �Ǽ�ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);

public:
	GroupPersonInfoDO() {
		is_pass = 1;
		test_num = "";
		id_card = "";
		person_name = "";
		sex = "";
		age = -1;
		physical_type = "";
		sporadic_physical = 1;
		dept = "";
		create_time = "";
	}
};

#endif // !_GROUP_PERSON_INFO_DO_

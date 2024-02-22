#pragma once
#ifndef _BASICINFORMATIONCONTROLLER_DO_
#define _BASICINFORMATIONCONTROLLER_DO_
#include "../DoInclude.h"

class BasicInformationDO
{
	// Ψһ���
	CC_SYNTHESIZE(string, person_id, Person_id);
	// ���⹤������
	CC_SYNTHESIZE(string, job, Job);
	// ��������
	CC_SYNTHESIZE(int, work_year, Work_year);
	// ��������
	CC_SYNTHESIZE(int, work_month, Work_month);
	// �Ӻ���ʼʱ��
	CC_SYNTHESIZE(string, exposure_start_date, Exposure_start_date);
	// �Ļ��̶�
	CC_SYNTHESIZE(string, education, Education);
	// ��ͥסַ
	CC_SYNTHESIZE(string, family_address, Family_address);
	// ����״��
	CC_SYNTHESIZE(string, marriage_date, Marriage_date);

public:
	BasicInformationDO() {
		person_id = "";
		job = "";
		work_year = -1;
		work_month = -1;
		exposure_start_date = "";
		education = "";
		family_address = "";
		marriage_date = "";
	}
};

#endif // !_GroupPerson_DO_

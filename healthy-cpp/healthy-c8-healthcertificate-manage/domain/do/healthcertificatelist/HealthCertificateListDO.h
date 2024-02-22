#pragma once

#ifndef _HEALTH_CERTIFICATE_LIST_DO_
#define _HEALTH_CERTIFICATE_LIST_DO_
#include "../DoInclude.h"

/**
 * �����б����ݿ�ʵ����
 */
class HealthCertificateListDO
{
	// ����֤����
	CC_SYNTHESIZE(string, health_ccertificate, Health_ccertificate);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// ��Ч����
	CC_SYNTHESIZE(string, term_of_validity, Term_of_validity);
	// ��֤��λ
	CC_SYNTHESIZE(string, unit_of_issue, Unit_of_issue);
	// ��ӡ״̬
	CC_SYNTHESIZE(int, print_state, Print_state);
	// �ϴ�״̬
	CC_SYNTHESIZE(int, is_upload, Is_upload);
public:
	HealthCertificateListDO() {
		health_ccertificate = "";
		name = "";
		sex = "";
		age = 0;
		term_of_validity = "";
		unit_of_issue = "";
		print_state = 0;
		is_upload = 0;
	}
};
#endif
#pragma once
#ifndef _GETPD_DO_
#define _GETPD_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class GetPDDO
{
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, work_name, Work_name);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	//���֤��
	CC_SYNTHESIZE(uint64_t, id_card, Id_card);
	//��ϵ�绰
	CC_SYNTHESIZE(uint64_t, phone, Phone);
public:
	GetPDDO() {
		
	}
};

#endif // !_SAMPLE_DO_
#pragma once
#ifndef _CHECKREPORTLIST_DO_
#define _CHECKREPORTLIST_DO_
#include "../DoInclude.h"

/**
 * ��ȡ�б����ݿ�ʵ����
 * ������Z
 */
class CheckReportListDO
{
	// ���
protected: string id; public: string getId(void) const {
	return id;
}public: void setId(string var) {
	id = var;
};
	// ����
	CC_SYNTHESIZE(string, person_name, Person_name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	//�Ƿ����
	CC_SYNTHESIZE(bool, statu, Statu);
	// �Ƿ��ӡ
	CC_SYNTHESIZE(bool, print_state, Print_state);
	// �Ƿ��������
	CC_SYNTHESIZE(bool, sporadic_physical, Sporadic_physical);
public:
	CheckReportListDO() {
		id = "";
		person_name = "";
		sex = "";
		age = 0;
		statu = false;
		print_state = false;
		sporadic_physical = false;
	}
};

#endif // !_CHECKREPORTLIST_DO_

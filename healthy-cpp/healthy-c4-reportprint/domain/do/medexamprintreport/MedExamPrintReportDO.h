#pragma once
#ifndef _MEDEXAMPRINTREPORT_DO_
#define _MEDEXAMPRINTREPORT_DO_
#include "../DoInclude.h"

/**
 * �����Ա���ݿ�ʵ����
 * �����ˣ�С��
 */
class MedExamPrintReportDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(uint32_t, age, Age);
	// ���
	CC_SYNTHESIZE(bool, statu, Statu);
	// ��ӡ
	CC_SYNTHESIZE(bool, printState, PrintState);
	// ���Ǽ��
	CC_SYNTHESIZE(bool, sporadicPhysical, SporadicPhysical);

public:
	MedExamPrintReportDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
		statu = false;
		printState = false;
		sporadicPhysical = false;
	}
};

#endif // !_MEDEXAMPRINTREPORT_DO_

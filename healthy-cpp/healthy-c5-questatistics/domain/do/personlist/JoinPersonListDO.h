#pragma once

#ifndef _JOINPERSONLIST_DO_
#define _JOINPERSONLIST_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class JoinPersonListDO
{
	// Ψһ���
	CC_SYNTHESIZE(string, id, Id);
	//�����
	CC_SYNTHESIZE(string, testNum, TestNum);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	//���֤��
	CC_SYNTHESIZE(int, idCard, IdCard);
	//���״̬
	CC_SYNTHESIZE(string, checkStatus, CheckStatus);
	//�ڸ�״̬
	CC_SYNTHESIZE(string, workStateText, WorkStateText);
	//Σ������
	CC_SYNTHESIZE(string, hazardFactor, HazardFactor);
	//�������
	CC_SYNTHESIZE(int, checkDate, CheckDate);
	//������
	CC_SYNTHESIZE(string, comments, Comments);
	//δ�����Ŀ
	CC_SYNTHESIZE(string, unfinishedTerm, UnfinishedTerm);
public:
	JoinPersonListDO() {
		id = "";
		testNum = "";
		name = "";
		sex = "";
		age = -1;
		idCard = 2;
		checkStatus = "";
		workStateText = "";
		hazardFactor = "";
		checkDate = 3;
		comments = "";
		unfinishedTerm = "";
	}
};

#endif // !_SAMPLE_DO_

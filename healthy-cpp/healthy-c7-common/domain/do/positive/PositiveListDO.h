#pragma once
#ifndef _POSITIVE_LIST_DO_
#define _POSITIVE_LIST_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class PositiveListDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, personName, PersonName);
	// �����
	CC_SYNTHESIZE(string, test_num, Test_Num);
	// ������
	CC_SYNTHESIZE(string, officeName,OfficeName);
	// �����Ŀ
	CC_SYNTHESIZE(string, order_group_item_project_name, Order_Group_Item_Project_Name);
	// ��� 
	CC_SYNTHESIZE(string, result, Result);
	// ��λ
	CC_SYNTHESIZE(string, unit_name, Unit_Name);
	// �ο���Χ
	CC_SYNTHESIZE(string, scope, Scope);
	// Σ���̶�
	CC_SYNTHESIZE(string,crisis_degree, Crisis_Degree);
	// �������
	CC_SYNTHESIZE(string, checkDate,CheckDate);
public:
	PositiveListDO() {
	}
};

#endif // !_SAMPLE_DO_
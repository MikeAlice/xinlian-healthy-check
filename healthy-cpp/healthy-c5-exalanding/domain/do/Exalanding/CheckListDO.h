#pragma once
#ifndef _CHECKLIST_DO_
#define _CHECKLIST_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class CheckListDO
{
	//��Ŀ���ƣ���ȷ��д��û�����������ݿ�t_lis��ġ����͡���item����
	CC_SYNTHESIZE(string, item, Item);
	//ԭ��
	CC_SYNTHESIZE(string, id_card, Id_card);
	//�ۿ�
	CC_SYNTHESIZE(int, discount, Discount);
	//�ۿۼ�
	CC_SYNTHESIZE(float, discount_price, Discount_price);
	//��Ŀ����
	CC_SYNTHESIZE(string, physical_type, Physical_type);
public:
	CheckListDO() {
		item = "";
		id_card = "";
		discount = 1;
		discount_price = 1;
		physical_type = "";
	}
};

#endif // !_CHECKLIST_DO_
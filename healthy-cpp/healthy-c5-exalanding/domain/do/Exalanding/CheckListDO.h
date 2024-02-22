#pragma once
#ifndef _CHECKLIST_DO_
#define _CHECKLIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class CheckListDO
{
	//项目名称（不确定写对没，先用了数据库t_lis里的“类型”，item。）
	CC_SYNTHESIZE(string, item, Item);
	//原价
	CC_SYNTHESIZE(string, id_card, Id_card);
	//折扣
	CC_SYNTHESIZE(int, discount, Discount);
	//折扣价
	CC_SYNTHESIZE(float, discount_price, Discount_price);
	//项目类型
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
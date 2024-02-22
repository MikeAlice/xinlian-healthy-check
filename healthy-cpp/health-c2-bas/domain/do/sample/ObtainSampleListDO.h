#pragma once
#ifndef _OBTAINSAMPLELIST_DO_
#define _OBTAINSAMPLELIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ObtainSampleListDO
{
	// 编号
	CC_SYNTHESIZE(string, id,Id);
	//名称
	CC_SYNTHESIZE(string, name, Name);
	//规格
	CC_SYNTHESIZE(string, spec, Spec);
	//样本代码
	CC_SYNTHESIZE(string, code, Code);
	//是否打印
	CC_SYNTHESIZE(unsigned int, is_print, Is_Print);
	//容量
	CC_SYNTHESIZE(string, capacity, Capacity);

	// 条码份数
	CC_SYNTHESIZE(unsigned int, barcode_num, Barcode_Num);
	//是否采血
	CC_SYNTHESIZE(unsigned int, need_take_blood, Need_Take_Blood);
	//排序
	CC_SYNTHESIZE(float, order_num, Order_Num);
	//关联码
	CC_SYNTHESIZE(string, liscode, Liscode);
public:
	ObtainSampleListDO() {
		id = "";
		name = "";
	}
};

#endif // !_OBTAINSAMPLELIST_DO_

#pragma once

#ifndef _INSERTSAMPLE_DO_
#define _INSERTSAMPLE_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类,用于数据库插入
 */
class InsertSampleDO
{
	//id
	CC_SYNTHESIZE(string, id, Id);
	//名称
	CC_SYNTHESIZE(string, name, Name);
	//规格
	CC_SYNTHESIZE(string, spec,Spec);
	//样本代码
	CC_SYNTHESIZE(string, code, Code);
	//是否打印
	CC_SYNTHESIZE(unsigned int, is_print, Is_print);
	//容量
	CC_SYNTHESIZE(string, capacity, Capacity);

	// 条码份数
	CC_SYNTHESIZE(unsigned int, barcode_num, Barcode_num);
	//是否采血
	CC_SYNTHESIZE(unsigned int, need_take_blood, Need_take_blood);
	//排序
	CC_SYNTHESIZE(float, order_num, Order_num);
	//关联码
	CC_SYNTHESIZE(string, liscode, Liscode);


	//del_flag
	CC_SYNTHESIZE(unsigned int, del_flag, Del_flag);

public:
	InsertSampleDO() {
		id = "";
		name = "";
		spec = "";
		code = "";
		is_print =1;
		capacity = "";
		barcode_num = 1;
		need_take_blood = 1;
		order_num = 1;
		liscode = "";
		del_flag = 0;
	}
};

#endif // !_INSERTSAMPLE_DO_

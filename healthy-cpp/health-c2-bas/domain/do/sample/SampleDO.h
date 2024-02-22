#pragma once

#ifndef _SAMPLE_DO_
#define _SAMPLE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class SampleDO
{
	// 主键
	CC_SYNTHESIZE(string, id, Id);
	//名称
	CC_SYNTHESIZE(string, name, Name);
	//规格
	CC_SYNTHESIZE(string, spec, Spec);
	//标本代码
	CC_SYNTHESIZE(string, code, Code);
	//是否打印
	CC_SYNTHESIZE(int32_t, is_print, Is_print);
	//容量
	CC_SYNTHESIZE(string, capacity, Capacity);
	//是否需要采血
	CC_SYNTHESIZE(int32_t, need_take_blood, Need_take_blood);
	//排序
	CC_SYNTHESIZE(double, order_num, Order_num);
	//关联码
	CC_SYNTHESIZE(string, liscode, Liscode);

public:
	SampleDO() {
		id = "";
		name = "";
		spec = "";
		code = "";
		is_print = -1;
		capacity = "";
		need_take_blood = -1;
		order_num = 0;
		liscode = "";

	}
};

#endif // !_SAMPLE_DO_


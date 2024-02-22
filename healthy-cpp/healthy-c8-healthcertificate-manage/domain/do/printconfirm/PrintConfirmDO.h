#pragma once
#ifndef _PRINT_CONFIRM_DO_
#define _PRINT_CONFIRM_DO_
#include "../DoInclude.h"

/**
 * 打印确认数据库实体类
 * 将DTO里面的类型转换成C++里面的类型
 * eg：OATPP中的String类型转换成C++中的string类型
 */
class PrintConfirmDO
{
	// 订单编号
	CC_SYNTHESIZE(string, orderid, Orderid);
public:
	PrintConfirmDO() {
		orderid = "";
	}
};

#endif // !_PRINT_CONFIRM_DO_
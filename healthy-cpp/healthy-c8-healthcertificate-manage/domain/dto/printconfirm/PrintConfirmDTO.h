#pragma once
#ifndef _PRINTCONFIRMDTO_H_
#define _PRINTCONFIRMDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 打印确认传输数据对象实体
 */
class PrintConfirmDTO :public oatpp::DTO
{
	//定义初始化
	DTO_INIT(PrintConfirmDTO, DTO);
	// 订单编号
	API_DTO_FIELD_DEFAULT(String, orderid, ZH_WORDS_GETTER("printconfirm.field.order-id"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PRINTCONFIRMDTO_H_

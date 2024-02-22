#pragma once
#ifndef _ORDERQUERY_H_
#define _ORDERQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 单位分页查询实体
*/

class OrderPersonQuery : public PageQuery
{
	//定义初始化
	DTO_INIT(OrderPersonQuery, PageQuery);
	// 分组id
	API_DTO_FIELD_DEFAULT(String, groupId, ZH_WORDS_GETTER("group.field.id"));
	// 订单id
	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("order.field.id"));
};


#include OATPP_CODEGEN_BEGIN(DTO)

#endif // !_ORDERQUERY_H_

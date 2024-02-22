#pragma once

#ifndef _ORDERLISTQUERY_H_
#define _ORDERLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取订单名称列表（条件+分页）    负责人：Chloe
 */

class OrderListQuery : public PageQuery
{
	//定义初始化
	DTO_INIT(OrderListQuery, PageQuery);
	//体检类型
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("order.field.physical_type"));
	//订单状态
	API_DTO_FIELD_DEFAULT(Int32, payStatus, ZH_WORDS_GETTER("order.field.pay_status"));
	//开始日期
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("order.field.start_date"));
	//结束日期
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("order.field.end_date"));
	//关键字
	API_DTO_FIELD_DEFAULT(String, searchKey, ZH_WORDS_GETTER("order.field.search_key"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ORDERLISTQUERY_H_



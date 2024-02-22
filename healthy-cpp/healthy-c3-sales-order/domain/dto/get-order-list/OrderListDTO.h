#pragma once

#ifndef _ORDERLISTDTO_H
#define _ORDERLISTDTO_H

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 订单列表传输数据对象实体
*/
class OrderListDTO : public oatpp::DTO
{
	//定义初始化
	DTO_INIT(OrderListDTO, DTO);

	//主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("order.field.id"));
	//订单编号
	API_DTO_FIELD_DEFAULT(String, orderCode, ZH_WORDS_GETTER("order.field.order_code"));
	//团检类型
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("order.field.physical_type"));
	//支付状态
	API_DTO_FIELD_DEFAULT(Int32, payStatus, ZH_WORDS_GETTER("order.field.pay_status"));
	//团检单位id
	API_DTO_FIELD_DEFAULT(String, groupUnitId, ZH_WORDS_GETTER("order.field.group_unit_id"));
	//团检单位名称
	API_DTO_FIELD_DEFAULT(String, groupUnitName, ZH_WORDS_GETTER("order.field.group_unit_name"));
	//签订日期
	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("order.field.signing_time"));
	//审核状态 -1 不审核 0 要审核 1处理中 2已通过 3未通过
	API_DTO_FIELD_DEFAULT(Int32, auditState, ZH_WORDS_GETTER("order.field.audit_state"));

};

/*
	单位列表分页数据实体
*/
class OrderListPageDTO :public PageDTO< OrderListDTO::Wrapper>
{
	DTO_INIT(OrderListPageDTO, PageDTO< OrderListDTO::Wrapper>);

};
#include OATPP_CODEGEN_END(DTO)
#endif
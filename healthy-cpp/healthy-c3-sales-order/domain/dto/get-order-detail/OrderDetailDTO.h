#pragma once

#ifndef _ORDERDETAILDTO_H_
#define _ORDERDETAILDTO_H_

#include "../../GlobalInclude.h"
#include "GroupDetailDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 查询订单详情
 */
class OrderDetailDTO : public oatpp::DTO
{
	DTO_INIT(OrderDetailDTO, DTO);

	//主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("order.field.id"));
	//订单编号
	API_DTO_FIELD_DEFAULT(String, orderCode, ZH_WORDS_GETTER("order.field.order_code"));
	//团检单位id
	API_DTO_FIELD_DEFAULT(String, groupUnitId, ZH_WORDS_GETTER("order.field.group_unit_id"));
	//团检单位名称
	API_DTO_FIELD_DEFAULT(String, groupUnitName, ZH_WORDS_GETTER("order.field.group_unit_name"));
	//销售负责人
	API_DTO_FIELD_DEFAULT(String, salesDirector, ZH_WORDS_GETTER("order.field.sales_director"));
	//销售负责人姓名
	API_DTO_FIELD_DEFAULT(String, salesDirectorName, ZH_WORDS_GETTER("order.field.sales_director_name"));
	//签订日期
	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("order.field.signing_time"));
	//检查日期
	API_DTO_FIELD_DEFAULT(String, deliveryTime, ZH_WORDS_GETTER("order.field.delivery_time"));
	//是否零星体检(0-否，1-是)
	API_DTO_FIELD_DEFAULT(Int32, sporadicPhysical, ZH_WORDS_GETTER("order.field.sporadic_physical"));
	//审核状态 -1 不审核 0 要审核 1处理中 2已通过 3未通过
	API_DTO_FIELD_DEFAULT(Int32, auditState, ZH_WORDS_GETTER("order.field.audit_state"));
	//分组
	API_DTO_FIELD_DEFAULT(List<GroupDetailDTO::Wrapper>, group, ZH_WORDS_GETTER("order.field.group"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ORDERDETAILDTO_H_


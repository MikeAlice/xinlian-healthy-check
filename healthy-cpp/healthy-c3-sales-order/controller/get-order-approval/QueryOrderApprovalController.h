#pragma once

#ifndef _ORDERVIEWAPPROVAL_CONTROLLER_
#define _ORDERVIEWAPPROVAL_CONTROLLER_
#include"../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../domain/dto/get-order-approval/OrderApprovalDTO.h"
#include "../../domain/vo/get-order-approval/OrderApprovalJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �鿴������Ϣ    �����ˣ��޵а�����
 */
class QueryOrderApprovalController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(QueryOrderApprovalController);
public:
// 	ENDPOINT_INFO(queryOrderApproval) {
// 		// ����ӿڱ���
// 		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("order.approval.summary"));
// 		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
// 		API_DEF_ADD_AUTH();
// 		// ������Ӧ������ʽ
// 		API_DEF_ADD_RSP_JSON_WRAPPER(OrderviewapprovalJsonVO);
// 		// �����ҳ��ѯ��������
// 		API_DEF_ADD_PAGE_PARAMS();
// 		// ����������ѯ��������
// 		  //��ѯ����
// 		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("order.field.type"),"type",true);
// 		  //��λ����
// 		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("order.field.name"),"peking",false);
// 		  //�������
// 		API_DEF_ADD_QUERY_PARAMS(String, "delivery_time", ZH_WORDS_GETTER("order.field.delivery_time"),"2020-9-9",true);
// 		  //���״̬
// 		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("order.field.status"),"finish",false);
// 		
// 	}
// 	//�����ѯ�ӿ�
// 	
// 	ENDPOINT(API_M_GET, "sales/order/get-approval", queryOrderApproval, QUERIES(QueryParams, params),API_HANDLER_AUTH_PARAME) {
// 		// ������ѯ����ΪQuery����ģ��
// 		API_HANDLER_QUERY_PARAM(userQuery, Orderviewapprovalquery, params);
// 		// ����ִ�к�����Ӧ���
// 		API_HANDLER_RESP_VO(execQueryOrderApproval(userQuery));
// 	}
	ENDPOINT_INFO(queryOrderApproval) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.approval.summary"), OrderApprovalJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "orderId", ZH_WORDS_GETTER("flow.field.group_order_id"), "1", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sales/order/get-approval/{orderId}", queryOrderApproval, PATH(String, orderId), execQueryOrderApproval(orderId));
private:
	OrderApprovalJsonVO::Wrapper execQueryOrderApproval(const String& orderId);
};
#include OATPP_CODEGEN_END(ApiController)
#endif

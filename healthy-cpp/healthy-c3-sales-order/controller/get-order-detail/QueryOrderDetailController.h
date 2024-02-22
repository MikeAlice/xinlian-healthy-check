#pragma once

#ifndef _QUERYORDERDETAILCONTROLLER_H_
#define _QUERYORDERDETAILCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "../../domain/vo/get-order-detail/OrderDetailVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * ��ȡ��������    �����ˣ����ǹ�
 */
/** 
* �޸ģ���ѯĳ�����������飬����ֻҪ����id�Ϳ�����
* �Ѳ���id����path�����Query�ﶼ��
*/
class QueryOrderDetailController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(QueryOrderDetailController);
public:
	ENDPOINT_INFO(queryOrderDetail) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.get-detail.summary"), OrderDetailJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("order.field.id"), "1", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sales/order/get-detail/{id}", queryOrderDetail, PATH(String, id), execQueryOrderDetail(id));
	 
private:
	// ��ѯ����
	OrderDetailJsonVO::Wrapper execQueryOrderDetail(const String& id);
	
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_QUERYORDERDETAILCONTROLLER_H_


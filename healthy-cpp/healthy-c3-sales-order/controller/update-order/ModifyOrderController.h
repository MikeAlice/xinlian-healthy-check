#pragma once

#ifndef _MODIFYORDERCONTROLLER_H_
#define _MODIFYORDERCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/get-order-detail/OrderDetailDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �޸Ķ���    �����ˣ�jimyy
 */
class ModifyOrderController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ModifyOrderController);
public: // 3 ����ӿ�
// 	// 3.1 ����ӿ�����
// 	// 3.2 ����ӿڴ���
	
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("order.put.summary"), modifyOrder, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/sales/order/update", modifyOrder, BODY_DTO(OrderDetailDTO::Wrapper, dto), execModifyOrder(dto, authObject->getPayload()));

private: // 3.3 ����ӿ�ִ�к���
	StringJsonVO::Wrapper execModifyOrder(const OrderDetailDTO::Wrapper& dto, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_MODIFYORDERCONTROLLER_H_

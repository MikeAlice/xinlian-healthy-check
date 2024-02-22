#pragma once

#ifndef _REMOVEORDERCONTROLLER_H_
#define _REMOVEORDERCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ɾ������    �����ˣ�Adam
 */
/*
* �޸ģ�Ψһ��ʶ��Ӧ���ݿ�id�ֶ�
* ɾ��ʱҪɾ���������ֹt_group_order
* ɾ������Ϊdel_flag���Ϊ1����ɾ������
*/
class RemoveOrderController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(RemoveOrderController);
	// 3 ����ӿ�
public:

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeOrder) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.delete.summary"), StringJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("order.field.id"), "1", true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sales/order/{id}", removeOrder, PATH(String, id), execRemoveOrder(id, authObject->getPayload()));
private:
	// ɾ������
	StringJsonVO::Wrapper execRemoveOrder(const String& id, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_REMOVEORDERCONTROLLER_H_
#pragma once
#ifndef _TypeTreeController_
#define _TypeTreeController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/typetree/TypeTreeQuery.h"
#include "domain/dto/typetree/TypeTreeDTO.h"
#include "domain/vo/typetree/TypeTreeVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class TypeTreeController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(TypeTreeController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryTypeTree) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("typetree.query-typetree.summary"), TypeTreeJsonVO::Wrapper);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/common/query-typetree", queryTypeTree, execQueryTypeTree(authObject->getPayload()));
private:
	// 3.3 ��������ʽ�������1
	TypeTreeJsonVO::Wrapper execQueryTypeTree(const PayloadDTO& payload);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
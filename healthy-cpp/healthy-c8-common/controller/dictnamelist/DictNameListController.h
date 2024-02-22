#pragma once
#ifndef _DictNameList_Controller_
#define _DictNameList_Controller_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/dictnamelist/DictNameListDTO.h"
#include "domain/vo/dictnamelist/DictNameListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class DictNameListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DictNameListController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryDictNameList) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("dictnamelist.query-dictnamelist.summary"), DictNameListJsonVO::Wrapper);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/common/query-dictnamelist", queryDictNameList, execQueryDictNameList(authObject->getPayload()));
private:
	// 3.3 ��������ʽ�������1
	DictNameListJsonVO::Wrapper execQueryDictNameList(const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
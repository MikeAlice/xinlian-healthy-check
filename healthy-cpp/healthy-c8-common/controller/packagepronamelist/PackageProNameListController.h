#pragma once
#ifndef _PackageProNameListController_
#define _PackageProNameListController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/packagepronamelist/PackageProNameListQuery.h"
#include "domain/dto/packagepronamelist/PackageProNameListDTO.h"
#include "domain/vo/packagepronamelist/PackageProNameListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PackageProNameListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PackageProNameListController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryPackageProNameList) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("packagepronamelist.query-packagepronamelist.summary"), PackageProNameListJsonVO::Wrapper);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/common/query-packagepronamelist", queryPackageProNameList, execQueryPackageProNameList(authObject->getPayload()));
private:
	// 3.3 ��������ʽ�������1
	PackageProNameListJsonVO::Wrapper execQueryPackageProNameList(const PayloadDTO& payload);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
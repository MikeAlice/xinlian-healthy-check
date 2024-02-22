#pragma once
#ifndef _PackageProList_Controller_
#define _PackageProList_Controller_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/packageprolist/PackageProListQuery.h"
#include "domain/dto/packageprolist/PackageProListDTO.h"
#include "domain/vo/packageprolist/PackageProListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PackageProListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PackageProListController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�2����
	ENDPOINT_INFO(queryPackageProList) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("packageprolist.query-packageprolist.summary"), PackageProListPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "keyword", ZH_WORDS_GETTER("packageprolist.field.keyword"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "section", ZH_WORDS_GETTER("packageprolist.field.section"), "", false);

	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/common/query-packageprolist", queryPackageProList, PackageProListQuery, execQueryPackageProList(query, authObject->getPayload()));
private:
	// 3.3 ��������ʽ�������2
	PackageProListPageJsonVO::Wrapper execQueryPackageProList(const PackageProListQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
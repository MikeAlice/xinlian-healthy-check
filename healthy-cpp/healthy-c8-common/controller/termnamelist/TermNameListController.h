#pragma once
#ifndef _TermNameListController_
#define _TermNameListController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/termnamelist/TermNameListQuery.h"
#include "domain/dto/termnamelist/TermNameListDTO.h"
#include "domain/vo/termnamelist/TermNameListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class TermNameListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(TermNameListController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryTermNameList) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("termnamelist.query-termnamelist.summary"), TermNameListPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "type_inspection", ZH_WORDS_GETTER("termnamelist.field.type_inspection"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "type_term", ZH_WORDS_GETTER("termnamelist.field.type_term"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "factor_danger", ZH_WORDS_GETTER("termnamelist.field.factor_danger"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "statu_on", ZH_WORDS_GETTER("termnamelist.field.statu_on"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "content_term", ZH_WORDS_GETTER("termnamelist.field.content_term"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_date", ZH_WORDS_GETTER("termnamelist.field.create_date"), "", false);

	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/common/query-termnamelist", queryTermNameList, TermNameListQuery, execQueryTermNameList(query, authObject->getPayload()));
private:
	// 3.3 ��������ʽ�������2
	TermNameListPageJsonVO::Wrapper execQueryTermNameList(const TermNameListQuery::Wrapper& query, const PayloadDTO& payload);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
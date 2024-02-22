#pragma once
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/query/contract/NameListQuery.h"
#include "../../domain/dto/contract/NameListDTO.h"
#include "../../domain/vo/contract/NameListVO.h"
#include "../../domain/query/contract/BaseInfoQuery.h"
#include "../../domain/dto/contract/BaseInfoDTO.h"
#include "../../domain/vo/contract/BaseInfoVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class NameListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(NameListController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryNameList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contract.get.summary1"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(NameListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt16, "auditState", ZH_WORDS_GETTER("contract.field.auditState"), 3, true);
		
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/contract/name-list", queryNameList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(nameListQuery, NameListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryNameList(nameListQuery));
	}

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryBaseInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contract.get.summary2"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(BaseInfoPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "signingTime", ZH_WORDS_GETTER("contract.field.signingTime"), "2021-10-1", true);
		API_DEF_ADD_QUERY_PARAMS(String, "groupUnitName", ZH_WORDS_GETTER("contract.field.groupUnitName"), "ucla", true);
		API_DEF_ADD_QUERY_PARAMS(UInt16, "auditState", ZH_WORDS_GETTER("contract.field.auditState"), 3, true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/contract/base-info", queryBaseInfo, QUERIES(QueryParams, Params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(baseInfoQuery, BaseInfoQuery, Params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryBaseInfo(baseInfoQuery));
	}

private:
	// 3.3 ��ʾ��ҳ��ѯ����
	NameListPageJsonVO::Wrapper execQueryNameList(const NameListQuery::Wrapper& query);
	// 3.3 ��ʾ��ѯ����
	BaseInfoJsonVO::Wrapper execQueryBaseInfo(const BaseInfoQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
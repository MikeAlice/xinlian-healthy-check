#pragma once
#ifndef _COUNTCHECK_CONTROLLER_
#define _COUNTCHECK_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "../../domain/vo/check/CountCheckVo.h"
#include "../../domain/query/check/CountCheckQuery.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class CountCheckController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(CountCheckController);
public:
	//  ���������ӿ�����
	ENDPOINT_INFO(CountCheck) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("countcheck.query-all.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CountCheckJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt32, "audit_level", ZH_WORDS_GETTER("countcheck.field.already"), 4, false);

	}
	//  ���������ӿڴ���
	ENDPOINT(API_M_GET, "/check", CountCheck, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, CountCheckQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryCountCheck(userQuery));
	}

private:
	//��ʾ��ѯ�������δ������
	CountCheckJsonVO::Wrapper execQueryCountCheck(const CountCheckQuery::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _COUNTCHECK_CONTROLLER_

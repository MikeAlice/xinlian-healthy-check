#pragma once

#ifndef _VIEW_EXCEPTION_CONTROLLER_
#define _VIEW_EXCEPTION_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/viewexception/ViewExceptionDTO.h" 
#include "domain/query/viewexception/ViewExceptionQuery.h"
#include "domain/vo/viewexception/ViewExceptionVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���÷���ӿڿ���������ʾ�����ӿڵ�ʹ��
 */
class ViewExceptionController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ViewExceptionController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryViewException) {
		// �ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("view-exception.get.summary"));
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧʽ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ViewExceptionJsonVO);

		// ����·������
		// ����֤���
		API_DEF_ADD_QUERY_PARAMS(String, "health_ccertificate", ZH_WORDS_GETTER("query-healthcertificatelist.field.hcid"), "10008", true);
	}
	ENDPOINT(API_M_GET, "/healthcertificate-manage/view-exception", queryViewException, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(viewException, ViewExceptionQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execViewException(viewException, authObject->getPayload()));
	}
private:
	ViewExceptionJsonVO::Wrapper execViewException(const ViewExceptionQuery::Wrapper& query, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
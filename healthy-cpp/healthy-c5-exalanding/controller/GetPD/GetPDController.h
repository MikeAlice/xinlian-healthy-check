#pragma once
#ifndef _GETPD_CONTROLLER_
#define _GETPD_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/GetPD/GetPDQuery.h"
#include "domain/dto/GetPD/GetPDDTO.h"
#include "domain/vo/GetPD/GetPDVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class GetPDController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(GetPDController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryGetPD) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("GetPD.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetPDPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("GetPD.field.name"), "aaa", true);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "id_card", ZH_WORDS_GETTER("GetPD.field.id_card"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "id", ZH_WORDS_GETTER("GetPD.field.id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "work_name", ZH_WORDS_GETTER("GetPD.field.work_name"), "N", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/GetPD", queryGetPD, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, GetPDQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryGetPD(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	GetPDPageJsonVO::Wrapper execQueryGetPD(const GetPDQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
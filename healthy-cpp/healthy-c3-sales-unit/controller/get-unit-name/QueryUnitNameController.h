#pragma once

#ifndef _QUERYUNITNAMECONTROLLER_H_
#define _QUERYUNITNAMECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/get-unit-name/UnitNameVO.h"
#include "../../domain/query/get-unit-name/UnitNameQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class QueryUnitNameController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(QueryUnitNameController);
public: // ����ӿ�
	// �����ҳ��ѯ��λ�б�ӿ�����
	ENDPOINT_INFO(queryUnitName) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.get-name.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitNamePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "physicalType", ZH_WORDS_GETTER("unit.field.physical_type"), "jian kang ti jian", true);
	}
	// �����ҳ��ѯ��λ�б�ӿ�
	ENDPOINT(API_M_GET, "/sales/unit/get-name", queryUnitName, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, UnitNameQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryUnitName(uq, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	UnitNamePageJsonVO::Wrapper execQueryUnitName(const UnitNameQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUERYUNITNAMECONTROLLER_H_

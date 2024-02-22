#pragma once

#ifndef _QUERYUNITLISTCONTROLLER_H_
#define _QUERYUNITLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/get-unit-list/UnitListVO.h"
#include "../../domain/query/get-unit-list/UnitListQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ��ȡ��λ�����б���������������б��    �����ˣ�Tutu��ͿͿ
 */
/**
 * �޸ģ����ݿ������������varchar
 */
class QueryUnitListController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(QueryUnitListController);
public: // ����ӿ�
	// �����ҳ��ѯ��λ�б�ӿ�����
	ENDPOINT_INFO(queryUnitList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.get-list.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//�������
		API_DEF_ADD_QUERY_PARAMS(String, "physicalType", ZH_WORDS_GETTER("unit.field.physical_type"), "jian kang ti jian", true);
		//��λ����
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("unit.field.name"), "z company", false);
		//ͳһ������ô���
		API_DEF_ADD_QUERY_PARAMS(String, "uscc", ZH_WORDS_GETTER("unit.field.uscc"), "lweeeee", false);
		//�����ϵ��
		API_DEF_ADD_QUERY_PARAMS(String, "linkMan2", ZH_WORDS_GETTER("unit.field.link_man2"), "lweeeee", false);
		//�����ϵ�˵绰
		API_DEF_ADD_QUERY_PARAMS(String, "linkPhone2", ZH_WORDS_GETTER("unit.field.link_phone2"), "lweeeee", false);
	}
	// �����ҳ��ѯ��λ�б�ӿ�
	ENDPOINT(API_M_GET, "/sales/unit/get-list", queryUnitList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, UnitListQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryUnitList(uq, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	UnitListPageJsonVO::Wrapper execQueryUnitList(const UnitListQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUERYUNITLISTCONTROLLER_H_

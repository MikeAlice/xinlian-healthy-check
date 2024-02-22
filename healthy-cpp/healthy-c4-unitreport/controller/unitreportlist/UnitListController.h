#pragma once

#ifndef _UNITLISTCONTROLLER_H_
#define _UNITLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/unitreportlist/UnitListVO.h"
#include "../../domain/query/unitreportlist/UnitPhysicalExaminationOrdersQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UnitListController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(UnitListController);
public://����ӿ�
	// �����ҳ��ѯ��쵥λ�����б�ӿ�����
	ENDPOINT_INFO(queryUnit) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unitreport.order.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//��λ����
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("unitreport.unit.name"),"",false );
		//���Ҷ���ǩ��ʱ��Ŀ�ʼʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "beginTime", ZH_WORDS_GETTER("unitreport.order.signingTime"), "", false );
		//���Ҷ���ǩ��ʱ��Ľ���ʱ��
		API_DEF_ADD_QUERY_PARAMS(String, "endTime", ZH_WORDS_GETTER("unitreport.order.signingTime"), "", false );
		//// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}

	// �����ҳ��ѯ��쵥λ�����б�ӿ�
	ENDPOINT(API_M_GET, "/unitreportlist/query-unit", queryUnit, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, UnitPhysicalExaminationOrdersQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryUnit(uq));
	}


private ://����ӿ�ִ�к���
	UnitListPageJsonVO::Wrapper execQueryUnit(const UnitPhysicalExaminationOrdersQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif 
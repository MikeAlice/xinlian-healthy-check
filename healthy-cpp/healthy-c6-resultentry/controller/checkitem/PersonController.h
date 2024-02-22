#pragma once
#ifndef _PERSON_CONTROLLER_
#define _PERSON_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "../../domain/vo/checkitem/PersonVO.h"
#include "../../domain/query/checkitem/PersonQuery.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class PersonController : public oatpp::web::server::api::ApiController {
	//����������������
	API_ACCESS_DECLARE(PersonController);
public:	//����ӿ�

	//�����ҳ��ѯ��λ�б�ӿ�����
	ENDPOINT_INFO(queryPerson) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("checkitem.filed.person_summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PersonJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("checkitem.person.id"), ZH_WORDS_GETTER("checkitem.person.eg_id"), true);
	}

	//�����ҳ��ѯ��λ�б�ӿ�
	ENDPOINT(API_M_GET, "/resultentry/checkitem/query-person", queryPerson, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(pq, PersonQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryPerson(pq));
	}

private:	//����ӿ�ִ�к���
	PersonPageJsonVO::Wrapper execQueryPerson(const PersonQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _Person_CONTROLLER_
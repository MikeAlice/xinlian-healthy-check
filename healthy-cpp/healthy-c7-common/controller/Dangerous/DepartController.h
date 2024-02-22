#pragma once
#ifndef _DEPARTCONTROLLER_H_
#define _DEPARTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Dangerous/DepartQuery.h"
#include "domain/dto/Dangerous/DepartListDTO.h"
#include "domain/vo/Dangerous/DepartVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class DepartController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(DepartController);
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryDepart) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Dangerous.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DepartListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//�����ԱID
		API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("depart.field.officeName"), "c82624d2a32bc9f711c62fa80f50df60", true);

	}

	ENDPOINT(API_M_GET, "/Dangerous/query-depart", queryDepart, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
	// ������ѯ����ΪQuery����ģ��
	API_HANDLER_QUERY_PARAM(qd, DepartQuery, params);
	// ����ִ�к�����Ӧ���
	API_HANDLER_RESP_VO(execQueryDepart(qd));
	}
private:
	DepartListPageJsonVO::Wrapper execQueryDepart(const DepartQuery::Wrapper& query);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITQUERY_H_
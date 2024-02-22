#pragma once
#ifndef _BASEPROJECT_CONTROLLER_
#define _BASEPROJECT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "../../domain/vo/checkitem/BaseProjectVO.h"
#include "../../domain/query/checkitem/BaseProjectQuery.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class BaseProjectController : public oatpp::web::server::api::ApiController {
	//����������������
	API_ACCESS_DECLARE(BaseProjectController);
public:	//����ӿ�

	//�����ҳ��ѯ��λ�б�ӿ�����
	ENDPOINT_INFO(queryBaseProject) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("checkitem.filed.project_summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(BaseProjectJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "portfolioId", ZH_WORDS_GETTER("checkitem.portfolio.id"), ZH_WORDS_GETTER("checkitem.portfolio.eg_id"), true);
	}

	//�����ҳ��ѯ��λ�б�ӿ�
	ENDPOINT(API_M_GET, "/resultentry/checkitem/query-baseproject", queryBaseProject, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(bpq, BaseProjectQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryBaseProject(bpq));
	}

private:	//����ӿ�ִ�к���
	BaseProjectPageJsonVO::Wrapper execQueryBaseProject(const BaseProjectQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _BASEPROJECT_CONTROLLER_
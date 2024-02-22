#ifndef _REPORTCONTROLLER_H_
#define _REPORTCONTROLLER_H_
#include"domain/vo/BaseJsonVO.h"
#include"../../domain/vo/report/ReportVO.h"
#include"../../domain/query/report/ReportQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class ReportController : public oatpp::web::server::api::ApiController {
	//����������������
	API_ACCESS_DECLARE(ReportController);
public:
	ENDPOINT_INFO(ReportCheck) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.choice"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ReportJsonVO);
		// ����������ѯ��������
		// Ψһ���
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("unit.id"), "XXXX", false);

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/report-choice", ReportCheck, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, IDQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execqueryReport(userQuery));
	}

private:
	ReportJsonVO::Wrapper execqueryReport(const IDQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)
#endif  



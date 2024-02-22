#ifndef _HEALTH_CERTIFICATE_CONTROLLER_
#define _HEALTH_CERTIFICATE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/healthcertificatelist/HealthCertificateQuery.h"
#include "domain/dto/healthcertificatelist/HealthCertificateDTO.h" 
#include "domain/vo/healthcertificatelist/HealthCertificateVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���÷���ӿڿ���������ʾ�����ӿڵ�ʹ��
 */
class HealthCertificateController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(HealthCertificateController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryHealthCertificateList) {
		// �ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("query-healthcertificatelist.get.summary"));
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧʽ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(HealthCertificateListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();

		// ����·������
		// ����֤���
		API_DEF_ADD_QUERY_PARAMS(String, "health_ccertificate", ZH_WORDS_GETTER("query-healthcertificatelist.field.hcid"), "10008", false);
		// �Ǽ�ʱ�䷶Χ����ʼ��
		API_DEF_ADD_QUERY_PARAMS(String, "start_date", ZH_WORDS_GETTER("query-healthcertificatelist.field.startDate"), "2024-01-05 00:00:01", false);
		// �Ǽ�ʱ�䷶Χ��������
		API_DEF_ADD_QUERY_PARAMS(String, "end_date", ZH_WORDS_GETTER("query-healthcertificatelist.field.endDate"), "2024-02-05 23:59:59", false);
		// ����
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("query-healthcertificatelist.field.name"), "LiHua", false);
		// �ձ�
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("query-healthcertificatelist.field.sex"), "male", false);
		// ����
		API_DEF_ADD_QUERY_PARAMS(Int32, "age", ZH_WORDS_GETTER("query-healthcertificatelist.field.age"), 18, false);
		// ��ӡ״̬
		API_DEF_ADD_QUERY_PARAMS(Int32, "print_state", ZH_WORDS_GETTER("query-healthcertificatelist.field.printState"), 0, false);
		// �ϴ�״̬
		API_DEF_ADD_QUERY_PARAMS(Int32, "is_upload", ZH_WORDS_GETTER("query-healthcertificatelist.field.isUpload"), 0, false);
	}
	ENDPOINT(API_M_GET, "/healthcertificate-manage/healthcertilist", queryHealthCertificateList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(healthCertificateList, HealthCertificateListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryHealthCertificateList(healthCertificateList, authObject->getPayload()));
	}
	// 3.2 �����������ʽ������õĽӿ�1����
private:
	HealthCertificateListPageJsonVO::Wrapper execQueryHealthCertificateList(const HealthCertificateListQuery::Wrapper& query, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
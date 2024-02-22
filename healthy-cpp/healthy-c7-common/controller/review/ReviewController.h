#pragma once
#ifndef _REVIEWCONTROLLER_H_
#define _REVIEWCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/review/ReviewQuery.h"
#include "domain/dto/review/ReviewListDTO.h"
#include "domain/vo/review/ReviewVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �����¼�������������ӿڵ�ʹ��
 */
class ReviewController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ReviewController);
	// 3 ����ӿ�
public:
	// 3.1 �����ҳ��ѯ�����¼�ӿ�����
	ENDPOINT_INFO(queryReview) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("review.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ReviewListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "personName", ZH_WORDS_GETTER("review.field.personName"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("review.field.personId"), "0001", false);
		//������Ŀcheck_project_id varchar(50)
		API_DEF_ADD_QUERY_PARAMS(String, "checkProjectId", ZH_WORDS_GETTER("review.field.checkProjectId"), "1234", false);
		API_DEF_ADD_QUERY_PARAMS(String, "checkProjectName", ZH_WORDS_GETTER("review.field.checkProjectName"), "abcd", false);
		//����˵��review_explain varchar(255)
		API_DEF_ADD_QUERY_PARAMS(String, "reviewExplain", ZH_WORDS_GETTER("review.field.reviewExplain"), "fall ill", false);
		//��������review_time` datetime '��������'
		API_DEF_ADD_QUERY_PARAMS(String, "reviewTime", ZH_WORDS_GETTER("review.field.reviewTime"), "2024-01-01", false);
		//�Ǽ�����create_time datetime '��������',
		API_DEF_ADD_QUERY_PARAMS(String, "createTime", ZH_WORDS_GETTER("review.field.createTime"), "2024-01-01", false);
		//�Ǽ�״̬state int '���״̬
		API_DEF_ADD_QUERY_PARAMS(UInt64, "state", ZH_WORDS_GETTER("review.field.state"), 1, false);
		//Σ������hazard_factor_code varchar(255)
		API_DEF_ADD_QUERY_PARAMS(String, "hazardFactorCode", ZH_WORDS_GETTER("review.field.hazardFactorCode"), "virus", false);
		//����
		
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/review/query-review", queryReview, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ReviewQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryReview(userQuery));
	}
	
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("review.put.summary"), modifyReview, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/review", modifyReview, BODY_DTO(ReviewListDTO::Wrapper, dto), execModifyReview(dto));

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeReview) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("review.delete.summary"), StringJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("review.field.id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/review/{id}", removeReview, PATH(String, id), execRemoveReview(id));

	// 3.1 ����Pdf�ӿ�����
	ENDPOINT_INFO(queryPdf) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("review.pdf.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ReviewJsonVO);
		// �����ҳ��ѯ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "personName", ZH_WORDS_GETTER("review.field.personName"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("review.field.personId"), "0001", false);
	}
	// 3.2 ����Pdf�ӿڴ���
	ENDPOINT(API_M_GET, "/review/pdf-review", queryPdf, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(pdfQuery, ReviewQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryPdf(pdfQuery));
	}

private: //����ӿ�ִ�к���
	// 3.3 ��ҳ��ѯ����
	ReviewListPageJsonVO::Wrapper execQueryReview(const ReviewQuery::Wrapper& query);
	// 3.3 �޸�����
	StringJsonVO::Wrapper execModifyReview(const ReviewListDTO::Wrapper& dto);
	// 3.3 ɾ������
	StringJsonVO::Wrapper execRemoveReview(const String& id);
	// 3.3 Pdf
	ReviewJsonVO::Wrapper execQueryPdf(const ReviewQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif //!_REVIEWCONTROLLER_H_
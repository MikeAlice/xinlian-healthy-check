#pragma once

#ifndef _REPORTSTATISTICSCONTROLLER_H_
#define _REPORTSTATISTICSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/ReportStatistics/ReportStatisticsVO.h"
#include "../../domain/query/ReportStatistics/ReportStatisticsQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class PhysicalExaminationPersonnelController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(PhysicalExaminationPersonnelController);
public://����ӿ�
	// �����ѯ�����Ա���ܱ�ӿ�����
	ENDPOINT_INFO(queryPhysicalExaminationPersonnel) 
	{
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unitreport.summaryTable.PhysicalExaminationPersonnel"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PhysicalExaminationPersonnelJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//�������
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("unitreport.order.code"), "", false);
		////ͳ�Ʊ���������������ʾ1��"�����Ա���ܱ�" 2��"������Ա���ܱ�" 3��"���������ܱ�"
		//API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("unitreport.summaryTable.type"), 1, true);
		//// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}

	// �����ѯ�����Ա���ܱ�ӿ�
	ENDPOINT(API_M_GET, "/ReportStatistics/PhysicalExaminationPersonnel", queryPhysicalExaminationPersonnel, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, ReportStatisticsQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryPhysicalExaminationPersonnel(uq));
	}

private://����ӿ�ִ�к���
	PhysicalExaminationPersonnelPageJsonVO::Wrapper execQueryPhysicalExaminationPersonnel(const ReportStatisticsQuery::Wrapper& query);

};

class ReviewPersonnelController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(ReviewPersonnelController);
public://����ӿ�
	// ����ӿ�����
	ENDPOINT_INFO(queryReviewPersonnel)
	{
		// �����ѯ������Ա���ܱ�ӿ�����
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unitreport.summaryTable.ReviewPersonnel"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ReviewPersonnelJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//�������
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("unitreport.order.code"), "", false);
		////ͳ�Ʊ���������������ʾ1��"�����Ա���ܱ�" 2��"������Ա���ܱ�" 3��"���������ܱ�"
		//API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("unitreport.summaryTable.type"), 2, true);
		//// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}

	// �����ѯ������Ա���ܱ�ӿ�
	ENDPOINT(API_M_GET, "/ReportStatistics/ReviewPersonnel", queryReviewPersonnel, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, ReportStatisticsQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryReviewPersonnel(uq));
	}

private://����ӿ�ִ�к���
	ReviewPersonnelPageJsonVO::Wrapper execQueryReviewPersonnel(const  ReportStatisticsQuery::Wrapper& query);

};

class ReviewResultsController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(ReviewResultsController);
public://����ӿ�
	// �����ѯ���������ܱ�ӿ�����
	ENDPOINT_INFO(queryReviewResults)
	{
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unitreport.summaryTable.ReviewResults"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ReviewResultsJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//�������
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("unitreport.order.code"), "", false);
		////ͳ�Ʊ���������������ʾ1��"�����Ա���ܱ�" 2��"������Ա���ܱ�" 3��"���������ܱ�"
		//API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("unitreport.summaryTable.type"), 3, true);
		//// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}

	// �����ѯ���������ܱ�ӿ�
	ENDPOINT(API_M_GET, "/ReportStatistics/ReviewResults", queryReviewResults, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, ReportStatisticsQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryReviewResults(uq));
	}

private://����ӿ�ִ�к���
	ReviewResultsPageJsonVO::Wrapper execQueryReviewResults(const ReportStatisticsQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif 
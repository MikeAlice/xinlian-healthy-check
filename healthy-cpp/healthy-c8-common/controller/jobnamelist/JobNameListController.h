#pragma once
#ifndef _JobNameList_Controller_
#define _JobNameList_Controller_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/jobnamelist/JobNameListQuery.h"
#include "domain/dto/jobnamelist/JobNameListDTO.h"
#include "domain/vo/jobnamelist/JobNameListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class JobNameListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(JobNameListController);
	// 3 ����ӿ�
public:
	// 3.1 �����������ʽ������õĽӿ�1����
	ENDPOINT_INFO(queryJobNameList) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("jobnamelist.query-jobnamelist.summary"), JobNameListPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ��������·������˵��
		API_DEF_ADD_QUERY_PARAMS(String, "keyword", ZH_WORDS_GETTER("jobnamelist.field.keyword"), "", false);
	}
	// 3.2 �����������ʽ������õĽӿ�1����
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/common/query-jobnamelist", queryJobNameList, JobNameListQuery, execQueryJobNameList(query, authObject->getPayload()));
private:
	// 3.3 ��������ʽ�������1
	JobNameListPageJsonVO::Wrapper execQueryJobNameList(const JobNameListQuery::Wrapper & query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
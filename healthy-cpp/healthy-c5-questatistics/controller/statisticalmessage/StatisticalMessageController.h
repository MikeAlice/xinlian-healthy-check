#pragma once

#ifndef _STATISTICALMESSAGECONTROLLER_H_
#define _STATISTICALMESSAGECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include"../../domain/vo/statisticalmessage/StatisticalMessageVO.h"
#include"../../domain/query/statisticalmessage/StatisticalMessageQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController) 


class StatisticalMessageController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(StatisticalMessageController);
	// 3 ����ӿ�
public:
	// 3.1 �����ҳ��ѯ��λ�б�ӿ�����
	ENDPOINT_INFO(queryStatisticalMessage) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("statistica.rate.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StatisticalMessagePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//��ѯ����
		API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("statistica.rate.type"), 1, true);
		//���״̬
		API_DEF_ADD_QUERY_PARAMS(UInt32, "isPass", ZH_WORDS_GETTER("statistica.rate.isPass"), 23, false);
	}
	//�����ҳ��ѯ��λ�б�ӿ�
	ENDPOINT(API_M_GET, "/statisticalmessage/rate", queryStatisticalMessage, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, StatisticalMessageQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryStatisticalMessage(uq));
	}
private:
	StatisticalMessagePageJsonVO::Wrapper execQueryStatisticalMessage(const StatisticalMessageQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_

#pragma once

#ifndef _JoinPersonListController_H_
#define _JoinPersonListController_H_

#include "domain/vo/BaseJsonVO.h"
#include"../../domain/vo/personlist/JoinPersonListVO.h"
#include"../../domain/query/personlist/JoinPersonListQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController) 


	class JoinPersonListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(JoinPersonListController);
	// 3 ����ӿ�
public:
	// 3.1 �����ҳ��ѯ��λ�б�ӿ�����
	ENDPOINT_INFO(queryPersonList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("check.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PersonListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//��ѯ����
		API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("check.field.type"), 1, true);
		//�����
		API_DEF_ADD_QUERY_PARAMS(UInt32, "testNum", ZH_WORDS_GETTER("check.field.testNum"), 23, false);
		//�������
		API_DEF_ADD_QUERY_PARAMS(String, "checkClass", ZH_WORDS_GETTER("check.field.checkClass"), "zzz", false);
		//����
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("check.field.name"), "hhh", false);
		//���֤��
		API_DEF_ADD_QUERY_PARAMS(UInt32, "idCard", ZH_WORDS_GETTER("check.field.idCard"), 111, false);
		//Σ������
		API_DEF_ADD_QUERY_PARAMS(String, "hazardFactor", ZH_WORDS_GETTER("check.field.hazardFactor"), "222", false);
		//״̬
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("check.field.status"), "aaa", false);
		//�Ա�
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("check.field.sex"), "fa", false);
		//�������
		API_DEF_ADD_QUERY_PARAMS(UInt32, "checkDate", ZH_WORDS_GETTER("check.field.checkDate"), 22, false);
		//������
		API_DEF_ADD_QUERY_PARAMS(String, "comments", ZH_WORDS_GETTER("check.field.comments"), "ydy", false);
	}
	//�����ҳ��ѯ��λ�б�ӿ�
	ENDPOINT(API_M_GET, "/personlist/query-check", queryPersonList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, JoinPersonListQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryPersonList(uq));
	}
private:
	PersonListPageJsonVO::Wrapper execQueryPersonList(const JoinPersonListQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_

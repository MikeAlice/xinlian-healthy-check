#pragma once
#ifndef _GROUP_PERSON_INFO_CONTROLLER_
#define _GROUP_PERSON_INFO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/GroupPersonInfo/GroupPersonInfoVO.h"
#include "../../domain/query/GroupPersonInfo/GroupPersonInfoQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GroupPersonInfoController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(GroupPersonInfoController);
public: // ����ӿ�
	// ������Ա�����ѯ�ӿ�����
	ENDPOINT_INFO(queryPersonInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("group_person.get.info"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GroupPersonInfoJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "test_num", ZH_WORDS_GETTER("group_person.data.test_num"), ZH_WORDS_GETTER("group_person.example.test_num"), true);
	};


	// ������Ա�����ѯ�ӿ�
	ENDPOINT(API_M_GET, "/resultentry/GroupPerson/Query/info", queryPersonInfo, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(infoQuery, GroupPersonInfoQuery, params);
		API_HANDLER_RESP_VO(queryPersonInfo(infoQuery));
	}
private: // ����ӿ�ִ�к���
	// ������Ա�����ѯ�ӿں���
	GroupPersonInfoJsonVO::Wrapper queryPersonInfo(const GroupPersonInfoQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GROUP_PERSON_INFO_CONTROLLER_
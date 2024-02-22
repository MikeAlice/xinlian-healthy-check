#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: duifang
 @Date: 2024/01/18

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _PEOPLELISTCONTROLLER_H_
#define _PEOPLELISTCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/Exalanding/PeopleListVO.h"
#include "../../domain/query/Exalanding/PeopleListQuery.h"
#include "../../../lib-oatpp/include/ApiHelper.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PeopleListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PeopleListController);
	// 3 ����ӿ�
public:

	// 3.1 �����ҳ��ѯ�����Ա�����б�ӿ�����
	ENDPOINT_INFO(queryPeopleList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("PeopleList.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PeopleListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//personName
		API_DEF_ADD_QUERY_PARAMS(String, "personName", ZH_WORDS_GETTER("Exalanding.field.personName"), u8"����", true);
		//�������
		API_DEF_ADD_QUERY_PARAMS(String, "physical", ZH_WORDS_GETTER("Exalanding.field.physical"), u8"ְ�����", true);
	}
	// 3.2 �����ҳ��ѯ�����Ա�����б�ӿ�
	ENDPOINT(API_M_GET, "/Exalanding/query-peoplelist", queryPeopleList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, PeopleListQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryPeopleList(uq));
	}
private:
	PeopleListPageJsonVO::Wrapper execQueryPeopleList(const PeopleListQuery::Wrapper& query);
	
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
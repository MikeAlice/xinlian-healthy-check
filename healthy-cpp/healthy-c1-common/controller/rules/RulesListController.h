#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: c1-pepper
 @Date: 2024/1/16

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
#ifndef _RULESLISTCONTROLLER_H_
#define _RULESLISTCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/rules/RulesListQuery.h"
#include "domain/query/rules/RulesListPageQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/rules/RulesListVO.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class RulesListController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(RulesListController);
public:
	// �����ѯ���й�����Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(queryAllRules) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("rules.query-all.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(RulesListJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/rules/query-all", queryAllRules, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, RulesListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeQueryAll(userQuery));
	}

	// �����ѯ���й�����Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(queryRules) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("rules.query-rules.summary"), RulesListJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("rules.field.id"), "123", true);
	}
	// �����ѯ�����û���Ϣ�ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/rules/query-rules", queryRules, RulesListQuery, executeQueryAll(query));


	// �����޸��û���Ϣ�˵�����
	ENDPOINT_INFO(modifyRules) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("rules.modify-rules.summary"), Uint64JsonVO::Wrapper);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/rules/modify-rules", modifyRules, BODY_DTO(RulesListDTO::Wrapper, dto), executeModifyRules(dto));

private:
	// ��ѯ����
	RulesListPageJsonVO::Wrapper executeQueryAll(const RulesListQuery::Wrapper& query);
	// �޸��û���Ϣ
	Uint64JsonVO::Wrapper executeModifyRules(const RulesListDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _RULESLISTCONTROLLER_H_
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���֮��
 @Date: 2024/01/17

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
#ifndef _ITEMRESULTCONTROLLER_H_
#define _ITEMRESULTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/itemResult/ItemResultVO.h"

#include "domain/query/itemResult/ItemResultQuery.h"
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ItemResultController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ItemResultController);
public: // ����ӿ�
	// �����ȡ�����Ŀ�����ϸ�ӿ�����
	ENDPOINT_INFO(queryItemResult) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("itemResult.get.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ����ӿ���Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ItemResultPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "itemId", ZH_WORDS_GETTER("itemResult.field.itemId"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("itemResult.field.personId"), "1", false);
	}
	// �����ȡ�����Ŀ�����ϸ�ӿ�
	ENDPOINT(API_M_GET, "/item-result", queryItemResult, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪItemResultQuery����ģ��
		API_HANDLER_QUERY_PARAM(iq, ItemResultQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryItemResult(iq, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	ItemResultPageJsonVO::Wrapper execQueryItemResult(const ItemResultQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ITEMRESULTCONTROLLER_H_
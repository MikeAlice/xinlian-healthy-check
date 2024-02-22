#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _CHECKLIST_CONTROLLER_
#define _CHECKLIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include"../../domain/vo/Exalanding/CheckListVO.h"
#include"../../domain/query/Exalanding/CheckListQuery.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class CheckListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(CheckListController);
public: // ����ӿ�
	ENDPOINT_INFO(queryCheckList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("check.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CheckListJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "item", ZH_WORDS_GETTER("sample.field.item"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "id_card", ZH_WORDS_GETTER("sample.field.id_card"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "discount", ZH_WORDS_GETTER("sample.field.discount"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Float64, "discount_price", ZH_WORDS_GETTER("sample.field.discount_price"), 1.0, false);
		API_DEF_ADD_QUERY_PARAMS(String, "physical_type", ZH_WORDS_GETTER("sample.field.physical_type"), "a", false);

	}

	ENDPOINT(API_M_GET, "/Exalanding/query-checklist", queryCheckList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, CheckListQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryCheckList(uq));
	}

	private: //����ӿ�ִ�к���
	CheckListPageJsonVO::Wrapper execQueryCheckList(const CheckListQuery::Wrapper& query);
	
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
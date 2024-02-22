#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���ܵ���
 @Date: 2024/1/19 17:36:29

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
#ifndef _ORDERNAME_CONTROLLER_
#define _ORDERNAME_CONTROLLER_

//#include "../../GlobalInclude.h"
#include "../../domain/dto/ordername/OrderNameDTO.h"
#include "../../domain/query/ordername/OrderNameQuery.h"
#include "../../domain/vo/ordername/OrderNameVO.h"
using namespace oatpp;
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class OrderNameController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(OrderNameController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryOrderName) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("ordername.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(OrderNamePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������

		//// ����
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("ordername.field.name"), "li ming", true);
		//// ����� 
		//API_DEF_ADD_QUERY_PARAMS(String, "checkId", ZH_WORDS_GETTER("ordername.field.checkId"), "1234567", false);
		//// �������
		//API_DEF_ADD_QUERY_PARAMS(String, "checkType", ZH_WORDS_GETTER("ordername.field.checkType"), "rrr", false);
		////���֤��
		//API_DEF_ADD_QUERY_PARAMS(String, "idCard", ZH_WORDS_GETTER("ordername.field.idCard"), "1234567234453322", false);
		////Σ������
		//API_DEF_ADD_QUERY_PARAMS(String, "dangerFactors", ZH_WORDS_GETTER("ordername.field.dangerFactors"), "ttt", false);
		////״̬
		//API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("ordername.field.state"), "www", false);
		////�Ա�
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("ordername.field.sex"), "N", false);
		
		////�������
		//API_DEF_ADD_QUERY_PARAMS(String, "checkDate", ZH_WORDS_GETTER("ordername.field.checkDate"), "2024-1-1", false);
		//��쵥λ��������
		API_DEF_ADD_QUERY_PARAMS(String, "unitName", ZH_WORDS_GETTER("ordername.field.unitName"), "yyyy", true);
	}

	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/healthy-c5-questatistics/ordername", queryOrderName, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, OrderNameQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryOrderName(userQuery, authObject->getPayload()));
	}





private:
	// 3.3 ��ʾ��ҳ��ѯ����
	OrderNamePageJsonVO::Wrapper execQueryOrderName(const OrderNameQuery::Wrapper& query, const PayloadDTO& payload);
};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_ORDERNAME_CONTROLLER_
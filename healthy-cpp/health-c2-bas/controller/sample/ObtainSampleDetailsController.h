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
#ifndef _OBTAIN_SAMPLE_DETAILS_CONTROLLER_
#define _OBTAIN_SAMPLE_DETAILS_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/sample/ObtainSampleDetailsQuery.h"
#include "domain/dto/sample/ObtainSampleDetailsDTO.h"
#include "domain/vo/sample/ObtainSampleDetailsVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ObtainSampleDetailsController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ObtainSampleDetailsController);
	// 3 ����ӿ�
public:

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(querySample) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sampleDetails.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ObtainSampleDetailsPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sampleDetails.field.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "barcode_num", ZH_WORDS_GETTER("sampleDetails.field.barcode_num"), 10, false);
		API_DEF_ADD_QUERY_PARAMS(String, "spec", ZH_WORDS_GETTER("sampleDetails.field.spec"), "", false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "need_take_blood", ZH_WORDS_GETTER("sampleDetails.field.need_take_blood"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("sampleDetails.field.code"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(Float32, "order_num", ZH_WORDS_GETTER("sampleDetails.field.order_num"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "is_print", ZH_WORDS_GETTER("sampleDetails.field.is_print"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "liscode", ZH_WORDS_GETTER("sampleDetails.field.liscode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "capacity", ZH_WORDS_GETTER("sampleDetails.field.capacity"), "", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/sample", querySample, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ObtainSampleDetailsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySampleDetails(userQuery, authObject->getPayload()));
	}
	
	
	// 3.3 ��ʾ��ҳ��ѯ����
	ObtainSampleDetailsPageJsonVO::Wrapper execQuerySampleDetails(const ObtainSampleDetailsQuery::Wrapper& query, const PayloadDTO& payload); 

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
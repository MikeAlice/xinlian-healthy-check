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

#ifndef _CONTRAINDICATIONS_CONTROLLER_
#define _CONTRAINDICATIONS_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/basis/ContraindicationsQuery.h"
#include "domain/dto/basis/ContraindicationsDTO.h"
#include "domain/vo/basis/ContraindicationsVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��ȡ����֤�����б������ʵ��
 */
class ContraindicationsController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(ContraindicationsController);

public:		// ����ӿ�

	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryContraindications) 
	{
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("basis.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ContraindicationsPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		
	}

	// �����ȡְҵ����֤�����б�ӿ�
	ENDPOINT(API_M_GET, "/basis/query-contraindications", queryContraindications, QUERIES(QueryParams, param), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(cq, ContraindicationsQuery, param);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryContraindications(cq, authObject->getPayload()));
	}

private:	// ����ӿ�ִ�к���
	ContraindicationsPageJsonVO::Wrapper execQueryContraindications(const ContraindicationsQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CONTRAINDICATIONS_CONTROLLER_
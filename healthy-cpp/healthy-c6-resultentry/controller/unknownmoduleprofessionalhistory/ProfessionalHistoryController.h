#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 11:19:05

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
#ifndef _PROFESSIONALHISTORYCONTRONLLER_CONTROLLER_
#define _PROFESSIONALHISTORYCONTRONLLER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/unknownmoduleprofessionalhistory/ProfessionalHistoryVO.h"
#include "domain/query/unknownmoduleprofessionalhistory/ProfessionalHistoryQuery.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "domain/GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class ProfessionalHistoryController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ProfessionalHistoryController);
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryProfessionalHistory) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.controller.tiile"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProfessionalHistoryPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "person_id", ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.controller.description"), "", false);
	}

	ENDPOINT(API_M_GET, "/resultentry/unknownmoduleprofessionalhistory/queryProfessionalHistory", queryProfessionalHistory, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(phq, ProfessionalHistoryQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProfessionalHistory(phq));
	}
private: // ����ӿ�ִ�к���
	ProfessionalHistoryPageJsonVO::Wrapper execQueryProfessionalHistory(const ProfessionalHistoryQuery::Wrapper& phq);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_

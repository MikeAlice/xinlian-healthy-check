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
#ifndef _PASTMEDICALHISTORYCONTRONLLER_CONTROLLER_
#define _PASTMEDICALHISTORYCONTRONLLER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/unknownmodulepastmedicalhistory/PastMedicalHistoryVO.h"
#include "domain/query/unknownmodulepastmedicalhistory/PastMedicalHistoryQuery.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "domain/GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作示例接口
 */
class PastMedicalHistoryController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(PastMedicalHistoryController);
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryPastMedicalHistory) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.controller.title"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PastMedicalHistoryPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "person_id", ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.controller.description"), "", false);
	}

	ENDPOINT(API_M_GET, "/resultentry/unknownmodulepastmedicalhistory/queryPastMedicalHistory", queryPastMedicalHistory, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(phq, PastMedicalHistoryQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPastMedicalHistory(phq));
	}
private: // 定义接口执行函数
	PastMedicalHistoryPageJsonVO::Wrapper execQueryPastMedicalHistory(const PastMedicalHistoryQuery::Wrapper& phq);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_

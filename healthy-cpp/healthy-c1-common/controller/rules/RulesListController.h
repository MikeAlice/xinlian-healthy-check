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
	// 添加访问定义
	API_ACCESS_DECLARE(RulesListController);
public:
	// 定义查询所有规则信息接口端点描述
	ENDPOINT_INFO(queryAllRules) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("rules.query-all.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(RulesListJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/rules/query-all", queryAllRules, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, RulesListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryAll(userQuery));
	}

	// 定义查询所有规则信息接口端点描述
	ENDPOINT_INFO(queryRules) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("rules.query-rules.summary"), RulesListJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("rules.field.id"), "123", true);
	}
	// 定义查询所有用户信息接口端点处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/rules/query-rules", queryRules, RulesListQuery, executeQueryAll(query));


	// 定义修改用户信息端点描述
	ENDPOINT_INFO(modifyRules) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("rules.modify-rules.summary"), Uint64JsonVO::Wrapper);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/rules/modify-rules", modifyRules, BODY_DTO(RulesListDTO::Wrapper, dto), executeModifyRules(dto));

private:
	// 查询所有
	RulesListPageJsonVO::Wrapper executeQueryAll(const RulesListQuery::Wrapper& query);
	// 修改用户信息
	Uint64JsonVO::Wrapper executeModifyRules(const RulesListDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _RULESLISTCONTROLLER_H_
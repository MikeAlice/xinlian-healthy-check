#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
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
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ItemResultController);
public: // 定义接口
	// 定义获取体检项目结果明细接口描述
	ENDPOINT_INFO(queryItemResult) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("itemResult.get.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义接口响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ItemResultPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "itemId", ZH_WORDS_GETTER("itemResult.field.itemId"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("itemResult.field.personId"), "1", false);
	}
	// 定义获取体检项目结果明细接口
	ENDPOINT(API_M_GET, "/item-result", queryItemResult, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为ItemResultQuery领域模型
		API_HANDLER_QUERY_PARAM(iq, ItemResultQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryItemResult(iq, authObject->getPayload()));
	}
private: // 定义接口执行函数
	ItemResultPageJsonVO::Wrapper execQueryItemResult(const ItemResultQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ITEMRESULTCONTROLLER_H_
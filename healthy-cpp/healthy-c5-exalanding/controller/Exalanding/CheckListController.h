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


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class CheckListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CheckListController);
public: // 定义接口
	ENDPOINT_INFO(queryCheckList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("check.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CheckListJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "item", ZH_WORDS_GETTER("sample.field.item"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "id_card", ZH_WORDS_GETTER("sample.field.id_card"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "discount", ZH_WORDS_GETTER("sample.field.discount"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Float64, "discount_price", ZH_WORDS_GETTER("sample.field.discount_price"), 1.0, false);
		API_DEF_ADD_QUERY_PARAMS(String, "physical_type", ZH_WORDS_GETTER("sample.field.physical_type"), "a", false);

	}

	ENDPOINT(API_M_GET, "/Exalanding/query-checklist", queryCheckList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, CheckListQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryCheckList(uq));
	}

	private: //定义接口执行函数
	CheckListPageJsonVO::Wrapper execQueryCheckList(const CheckListQuery::Wrapper& query);
	
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
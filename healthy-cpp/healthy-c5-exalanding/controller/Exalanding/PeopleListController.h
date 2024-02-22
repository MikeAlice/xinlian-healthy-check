#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: duifang
 @Date: 2024/01/18

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
#ifndef _PEOPLELISTCONTROLLER_H_
#define _PEOPLELISTCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/Exalanding/PeopleListVO.h"
#include "../../domain/query/Exalanding/PeopleListQuery.h"
#include "../../../lib-oatpp/include/ApiHelper.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * 示例控制器，演示基础接口的使用
 */
class PeopleListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PeopleListController);
	// 3 定义接口
public:

	// 3.1 定义分页查询体检人员名称列表接口描述
	ENDPOINT_INFO(queryPeopleList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("PeopleList.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PeopleListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//personName
		API_DEF_ADD_QUERY_PARAMS(String, "personName", ZH_WORDS_GETTER("Exalanding.field.personName"), u8"王五", true);
		//体检类型
		API_DEF_ADD_QUERY_PARAMS(String, "physical", ZH_WORDS_GETTER("Exalanding.field.physical"), u8"职工体检", true);
	}
	// 3.2 定义分页查询体检人员名称列表接口
	ENDPOINT(API_M_GET, "/Exalanding/query-peoplelist", queryPeopleList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, PeopleListQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPeopleList(uq));
	}
private:
	PeopleListPageJsonVO::Wrapper execQueryPeopleList(const PeopleListQuery::Wrapper& query);
	
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
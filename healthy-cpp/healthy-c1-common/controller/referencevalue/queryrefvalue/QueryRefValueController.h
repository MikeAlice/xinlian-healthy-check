#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2024/01/14
 @FileName: QueryRefValueController
 @version: 1.0

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
#ifndef _QUERY_REF_VALUE_CONTROLLER_H_
#define _QUERY_REF_VALUE_CONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/referencevalue/RefValuePageQuery.h"
#include "domain/vo/referencevalue/RefValuePageJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
class QueryRefValueController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(QueryRefValueController);
public:// 定义接口
	// 获取数据列表（分页+条件） 负责人：超能
	ENDPOINT_INFO(queryRefValue) {
		// 该端点的描述信息
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("common.reference_value.controller.query.summary"));
		// 添加安全验证
		API_DEF_ADD_AUTH();
		// 定义分页查询参数描述(请求)
		API_DEF_ADD_PAGE_PARAMS();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(RefValuePageJsonVO);
		// 适合性别
		API_DEF_ADD_QUERY_PARAMS(String, "allow_sex", ZH_WORDS_GETTER("common.reference_value.field.allow_sex"), , false);
		// 年龄最低值
		API_DEF_ADD_QUERY_PARAMS(Int64, "min_age", ZH_WORDS_GETTER("common.reference_value.field.min_age"), , false);
		// 年龄最高值
		API_DEF_ADD_QUERY_PARAMS(Int64, "max_age", ZH_WORDS_GETTER("common.reference_value.field.max_age"), , false);
		// 健康参考值
		API_DEF_ADD_QUERY_PARAMS(String, "healthy_value", ZH_WORDS_GETTER("common.reference_value.field.healthy_value"), , false);
		// 职业参考值
		API_DEF_ADD_QUERY_PARAMS(String, "occupation_value", ZH_WORDS_GETTER("common.reference_value.field.occupation_value"), , false);
	}

	ENDPOINT(API_M_GET, "/common/relationProject/QueryReferenceValue", queryRefValue, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(refValueQuery, RefValuePageQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryRefValue(refValueQuery, authObject->getPayload()));
	}
private:
	// 获取数据列表（分页+条件） 负责人：超能
	RefValuePageJsonVO::Wrapper execQueryRefValue(const RefValuePageQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif

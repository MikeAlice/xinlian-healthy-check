#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: smartPiggy
 @Date: 2024-01-18

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
#ifndef _RESULTCONTROLLER_H_
#define _RESULTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include"../../domain/query/result/ResultQuery.h"
#include"../../domain/dto/result/ResultDTO.h"
#include"../../domain/vo/result/ResultVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class ResultController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(ResultController);
public: //定义接口

	//1.1项目结论查询接口描述
	ENDPOINT_INFO(queryResult) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("result.query.list"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ResultPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//人员ID
		API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("result.field.personId"),"001",true);
	}
	//1.2项目结论查询接口处理
	ENDPOINT(API_M_GET, "/result/depart-result", queryResult, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{  
		// 解析查询参数为Query领域模型（接收Browser层的Query）,解析得到resultQuery
		API_HANDLER_QUERY_PARAM(resultQuery, ResultQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPrimCheck(resultQuery));
	}
private: //定义接口执行函数
	ResultPageJsonVO::Wrapper execQueryPrimCheck(const ResultQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_RESULTCONTROLLER_H_
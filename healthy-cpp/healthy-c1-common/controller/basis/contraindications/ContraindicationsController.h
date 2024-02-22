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

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 获取禁忌证术语列表控制器实体
 */
class ContraindicationsController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ContraindicationsController);

public:		// 定义接口

	// 定义查询接口描述
	ENDPOINT_INFO(queryContraindications) 
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("basis.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ContraindicationsPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		
	}

	// 定义获取职业禁忌证术语列表接口
	ENDPOINT(API_M_GET, "/basis/query-contraindications", queryContraindications, QUERIES(QueryParams, param), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(cq, ContraindicationsQuery, param);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryContraindications(cq, authObject->getPayload()));
	}

private:	// 定义接口执行函数
	ContraindicationsPageJsonVO::Wrapper execQueryContraindications(const ContraindicationsQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CONTRAINDICATIONS_CONTROLLER_
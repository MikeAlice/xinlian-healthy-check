#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 会跑的鱼
 @Date: 2024/1/19 17:36:29

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
#ifndef _ORDERNAME_CONTROLLER_
#define _ORDERNAME_CONTROLLER_

//#include "../../GlobalInclude.h"
#include "../../domain/dto/ordername/OrderNameDTO.h"
#include "../../domain/query/ordername/OrderNameQuery.h"
#include "../../domain/vo/ordername/OrderNameVO.h"
using namespace oatpp;
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class OrderNameController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(OrderNameController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryOrderName) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("ordername.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(OrderNamePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述

		//// 姓名
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("ordername.field.name"), "li ming", true);
		//// 体检编号 
		//API_DEF_ADD_QUERY_PARAMS(String, "checkId", ZH_WORDS_GETTER("ordername.field.checkId"), "1234567", false);
		//// 检查种类
		//API_DEF_ADD_QUERY_PARAMS(String, "checkType", ZH_WORDS_GETTER("ordername.field.checkType"), "rrr", false);
		////身份证号
		//API_DEF_ADD_QUERY_PARAMS(String, "idCard", ZH_WORDS_GETTER("ordername.field.idCard"), "1234567234453322", false);
		////危害因素
		//API_DEF_ADD_QUERY_PARAMS(String, "dangerFactors", ZH_WORDS_GETTER("ordername.field.dangerFactors"), "ttt", false);
		////状态
		//API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("ordername.field.state"), "www", false);
		////性别
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("ordername.field.sex"), "N", false);
		
		////体检日期
		//API_DEF_ADD_QUERY_PARAMS(String, "checkDate", ZH_WORDS_GETTER("ordername.field.checkDate"), "2024-1-1", false);
		//体检单位订单名称
		API_DEF_ADD_QUERY_PARAMS(String, "unitName", ZH_WORDS_GETTER("ordername.field.unitName"), "yyyy", true);
	}

	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/healthy-c5-questatistics/ordername", queryOrderName, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, OrderNameQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryOrderName(userQuery, authObject->getPayload()));
	}





private:
	// 3.3 演示分页查询数据
	OrderNamePageJsonVO::Wrapper execQueryOrderName(const OrderNameQuery::Wrapper& query, const PayloadDTO& payload);
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_ORDERNAME_CONTROLLER_
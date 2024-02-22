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
#ifndef _TICKETGROUPNAMELISTGONTROLLER_H_
#define _TICKETGROUPNAMELISTGONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/Exalanding/TicketGroupNameListVO.h"
#include "../../domain/query/Exalanding/TicketGroupNameListQuery.h"
#include "../../../lib-oatpp/include/ApiHelper.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * 示例控制器，演示基础接口的使用
 */
class TicketGroupNameListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(TicketGroupNameListController);
	// 3 定义接口
public:

	// 3.1 定义团单名称列表接口描述
	ENDPOINT_INFO(queryTicketGroupNameList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("queryTicketGroupNameList.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(TicketGroupNameListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//Name
		API_DEF_ADD_QUERY_PARAMS(String, "Unit_name", ZH_WORDS_GETTER("Exalanding.field.Unit_name"), u8"测试", true);
	}
	// 3.2 定义分页查询体检人员名称列表接口
	ENDPOINT(API_M_GET, "/Exalanding/query-TicketGroupNameList", queryTicketGroupNameList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, TicketGroupNameListQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryTicketGroupNameList(uq));
	}
private:
	TicketGroupNameListPageJsonVO::Wrapper execQueryTicketGroupNameList(const TicketGroupNameListQuery::Wrapper& query);
	
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
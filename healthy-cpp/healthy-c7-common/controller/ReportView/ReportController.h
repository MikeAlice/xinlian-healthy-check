#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: DY
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
#ifndef _REPORT_CONTROLLER_
#define _REPORT_CONTROLLER_

#include "domain/query/ReportView/ReportQuery.h"
#include "domain/vo/ReportView/ReportVO.h"

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"



// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class ReportController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ReportController);

public:
	
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryReport) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("report.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ReportJsonVO);
		
		// 姓名ID
		API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("report.field.personId"), "1", true);
	
	}
	

	

	
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/report", queryReport, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, ReportQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryreport(uq));
	}

	
	
	
	

private:

	// 执行单文件上传处理
	//StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);


	ReportJsonVO::Wrapper execQueryreport(const ReportQuery::Wrapper& query);

};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _REPORT_CONTROLLER_
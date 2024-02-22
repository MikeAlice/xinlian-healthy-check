#pragma once

#ifndef _VIEW_EXCEPTION_CONTROLLER_
#define _VIEW_EXCEPTION_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/viewexception/ViewExceptionDTO.h" 
#include "domain/query/viewexception/ViewExceptionQuery.h"
#include "domain/vo/viewexception/ViewExceptionVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 公用服务接口控制器，演示基础接口的使用
 */
class ViewExceptionController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ViewExceptionController);
	// 3 定义接口
public:
	// 3.1 定义测试声明式服务调用的接口1描述
	ENDPOINT_INFO(queryViewException) {
		// 接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("view-exception.get.summary"));
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应式参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ViewExceptionJsonVO);

		// 其他路径参数
		// 健康证编号
		API_DEF_ADD_QUERY_PARAMS(String, "health_ccertificate", ZH_WORDS_GETTER("query-healthcertificatelist.field.hcid"), "10008", true);
	}
	ENDPOINT(API_M_GET, "/healthcertificate-manage/view-exception", queryViewException, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(viewException, ViewExceptionQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execViewException(viewException, authObject->getPayload()));
	}
private:
	ViewExceptionJsonVO::Wrapper execViewException(const ViewExceptionQuery::Wrapper& query, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
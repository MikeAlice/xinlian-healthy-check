#pragma once
#ifndef _COUNTCHECK_CONTROLLER_
#define _COUNTCHECK_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "../../domain/vo/check/CountCheckVo.h"
#include "../../domain/query/check/CountCheckQuery.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class CountCheckController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(CountCheckController);
public:
	//  定义新增接口描述
	ENDPOINT_INFO(CountCheck) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("countcheck.query-all.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CountCheckJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt32, "audit_level", ZH_WORDS_GETTER("countcheck.field.already"), 4, false);

	}
	//  定义新增接口处理
	ENDPOINT(API_M_GET, "/check", CountCheck, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, CountCheckQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryCountCheck(userQuery));
	}

private:
	//演示查询已审核与未审核完成
	CountCheckJsonVO::Wrapper execQueryCountCheck(const CountCheckQuery::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _COUNTCHECK_CONTROLLER_

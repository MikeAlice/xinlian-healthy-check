#pragma once

#ifndef _STATISTICALMESSAGECONTROLLER_H_
#define _STATISTICALMESSAGECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include"../../domain/vo/statisticalmessage/StatisticalMessageVO.h"
#include"../../domain/query/statisticalmessage/StatisticalMessageQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController) 


class StatisticalMessageController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(StatisticalMessageController);
	// 3 定义接口
public:
	// 3.1 定义分页查询单位列表接口描述
	ENDPOINT_INFO(queryStatisticalMessage) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("statistica.rate.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StatisticalMessagePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//查询类型
		API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("statistica.rate.type"), 1, true);
		//体检状态
		API_DEF_ADD_QUERY_PARAMS(UInt32, "isPass", ZH_WORDS_GETTER("statistica.rate.isPass"), 23, false);
	}
	//定义分页查询单位列表接口
	ENDPOINT(API_M_GET, "/statisticalmessage/rate", queryStatisticalMessage, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, StatisticalMessageQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryStatisticalMessage(uq));
	}
private:
	StatisticalMessagePageJsonVO::Wrapper execQueryStatisticalMessage(const StatisticalMessageQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_

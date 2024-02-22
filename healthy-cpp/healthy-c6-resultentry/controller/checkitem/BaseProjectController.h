#pragma once
#ifndef _BASEPROJECT_CONTROLLER_
#define _BASEPROJECT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "../../domain/vo/checkitem/BaseProjectVO.h"
#include "../../domain/query/checkitem/BaseProjectQuery.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class BaseProjectController : public oatpp::web::server::api::ApiController {
	//定义控制器访问入口
	API_ACCESS_DECLARE(BaseProjectController);
public:	//定义接口

	//定义分页查询单位列表接口描述
	ENDPOINT_INFO(queryBaseProject) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("checkitem.filed.project_summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BaseProjectJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "portfolioId", ZH_WORDS_GETTER("checkitem.portfolio.id"), ZH_WORDS_GETTER("checkitem.portfolio.eg_id"), true);
	}

	//定义分页查询单位列表接口
	ENDPOINT(API_M_GET, "/resultentry/checkitem/query-baseproject", queryBaseProject, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(bpq, BaseProjectQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryBaseProject(bpq));
	}

private:	//定义接口执行函数
	BaseProjectPageJsonVO::Wrapper execQueryBaseProject(const BaseProjectQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _BASEPROJECT_CONTROLLER_
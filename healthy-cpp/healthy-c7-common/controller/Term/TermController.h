#pragma once
#ifndef _TERMCONTROLLER_H_
#define _TERMCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/term/TermVO.h"
#include "../../domain//query/term/TermQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TermController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(TermController);
public://定义接口
	//定义分页查询单位列表接口描述
	ENDPOINT_INFO(queryTerm) {
		//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("term.query.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义相应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(TermListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "officeId", ZH_WORDS_GETTER("term.field.officeId"), "00000", true);
		API_DEF_ADD_QUERY_PARAMS(String, "hazardFactorsText", ZH_WORDS_GETTER("term.field.hazardFactorsText"),"",false);
		API_DEF_ADD_QUERY_PARAMS(String, "inspectType", ZH_WORDS_GETTER("term.field.inspectType"),"体检",true);
		API_DEF_ADD_QUERY_PARAMS(String, "content", ZH_WORDS_GETTER("term.field.content"),"",false);
		API_DEF_ADD_QUERY_PARAMS(String, "workStateText", ZH_WORDS_GETTER("term.field.workStateText"),"",false);
	}

	


	//定义分页查询单位列表
	ENDPOINT(API_M_GET, "/Term/query-term", queryTerm, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		//解析查询参数未Query领域模型
		API_HANDLER_QUERY_PARAM(tq, TermQuery, params);
		//呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryTerm(tq));
	}
private://定义接口执行函数
	TermListPageJsonVO::Wrapper execQueryTerm(const TermQuery::Wrapper& query);

};



#include OATPP_CODEGEN_END(ApiController)

#endif
#pragma once
#ifndef _TermNameListController_
#define _TermNameListController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/termnamelist/TermNameListQuery.h"
#include "domain/dto/termnamelist/TermNameListDTO.h"
#include "domain/vo/termnamelist/TermNameListVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class TermNameListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(TermNameListController);
	// 3 定义接口
public:
	// 3.1 定义测试声明式服务调用的接口1描述
	ENDPOINT_INFO(queryTermNameList) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("termnamelist.query-termnamelist.summary"), TermNameListPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "type_inspection", ZH_WORDS_GETTER("termnamelist.field.type_inspection"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "type_term", ZH_WORDS_GETTER("termnamelist.field.type_term"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "factor_danger", ZH_WORDS_GETTER("termnamelist.field.factor_danger"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "statu_on", ZH_WORDS_GETTER("termnamelist.field.statu_on"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "content_term", ZH_WORDS_GETTER("termnamelist.field.content_term"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_date", ZH_WORDS_GETTER("termnamelist.field.create_date"), "", false);

	}
	// 3.2 定义测试声明式服务调用的接口1处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/common/query-termnamelist", queryTermNameList, TermNameListQuery, execQueryTermNameList(query, authObject->getPayload()));
private:
	// 3.3 测试声明式服务调用2
	TermNameListPageJsonVO::Wrapper execQueryTermNameList(const TermNameListQuery::Wrapper& query, const PayloadDTO& payload);
};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
#pragma once
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/query/contract/NameListQuery.h"
#include "../../domain/dto/contract/NameListDTO.h"
#include "../../domain/vo/contract/NameListVO.h"
#include "../../domain/query/contract/BaseInfoQuery.h"
#include "../../domain/dto/contract/BaseInfoDTO.h"
#include "../../domain/vo/contract/BaseInfoVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class NameListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(NameListController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryNameList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contract.get.summary1"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(NameListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt16, "auditState", ZH_WORDS_GETTER("contract.field.auditState"), 3, true);
		
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/contract/name-list", queryNameList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(nameListQuery, NameListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryNameList(nameListQuery));
	}

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryBaseInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contract.get.summary2"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BaseInfoPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "signingTime", ZH_WORDS_GETTER("contract.field.signingTime"), "2021-10-1", true);
		API_DEF_ADD_QUERY_PARAMS(String, "groupUnitName", ZH_WORDS_GETTER("contract.field.groupUnitName"), "ucla", true);
		API_DEF_ADD_QUERY_PARAMS(UInt16, "auditState", ZH_WORDS_GETTER("contract.field.auditState"), 3, true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/contract/base-info", queryBaseInfo, QUERIES(QueryParams, Params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(baseInfoQuery, BaseInfoQuery, Params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryBaseInfo(baseInfoQuery));
	}

private:
	// 3.3 演示分页查询数据
	NameListPageJsonVO::Wrapper execQueryNameList(const NameListQuery::Wrapper& query);
	// 3.3 演示查询数据
	BaseInfoJsonVO::Wrapper execQueryBaseInfo(const BaseInfoQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
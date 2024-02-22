#pragma once

#ifndef _QUERYUNITNAMECONTROLLER_H_
#define _QUERYUNITNAMECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/get-unit-name/UnitNameVO.h"
#include "../../domain/query/get-unit-name/UnitNameQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class QueryUnitNameController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(QueryUnitNameController);
public: // 定义接口
	// 定义分页查询单位列表接口描述
	ENDPOINT_INFO(queryUnitName) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.get-name.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitNamePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "physicalType", ZH_WORDS_GETTER("unit.field.physical_type"), "jian kang ti jian", true);
	}
	// 定义分页查询单位列表接口
	ENDPOINT(API_M_GET, "/sales/unit/get-name", queryUnitName, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, UnitNameQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryUnitName(uq, authObject->getPayload()));
	}
private: // 定义接口执行函数
	UnitNamePageJsonVO::Wrapper execQueryUnitName(const UnitNameQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUERYUNITNAMECONTROLLER_H_

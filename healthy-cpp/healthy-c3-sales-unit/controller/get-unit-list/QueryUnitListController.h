#pragma once

#ifndef _QUERYUNITLISTCONTROLLER_H_
#define _QUERYUNITLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/get-unit-list/UnitListVO.h"
#include "../../domain/query/get-unit-list/UnitListQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 获取单位名称列表（用于输入表单下拉列表框）    负责人：Tutu糊涂涂
 */
/**
 * 修改：数据库中体检类型是varchar
 */
class QueryUnitListController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(QueryUnitListController);
public: // 定义接口
	// 定义分页查询单位列表接口描述
	ENDPOINT_INFO(queryUnitList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.get-list.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//体检类型
		API_DEF_ADD_QUERY_PARAMS(String, "physicalType", ZH_WORDS_GETTER("unit.field.physical_type"), "jian kang ti jian", true);
		//单位名称
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("unit.field.name"), "z company", false);
		//统一社会信用代码
		API_DEF_ADD_QUERY_PARAMS(String, "uscc", ZH_WORDS_GETTER("unit.field.uscc"), "lweeeee", false);
		//体检联系人
		API_DEF_ADD_QUERY_PARAMS(String, "linkMan2", ZH_WORDS_GETTER("unit.field.link_man2"), "lweeeee", false);
		//体检联系人电话
		API_DEF_ADD_QUERY_PARAMS(String, "linkPhone2", ZH_WORDS_GETTER("unit.field.link_phone2"), "lweeeee", false);
	}
	// 定义分页查询单位列表接口
	ENDPOINT(API_M_GET, "/sales/unit/get-list", queryUnitList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, UnitListQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryUnitList(uq, authObject->getPayload()));
	}
private: // 定义接口执行函数
	UnitListPageJsonVO::Wrapper execQueryUnitList(const UnitListQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUERYUNITLISTCONTROLLER_H_

#pragma once

#ifndef _UNITLISTCONTROLLER_H_
#define _UNITLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/unitreportlist/UnitListVO.h"
#include "../../domain/query/unitreportlist/UnitPhysicalExaminationOrdersQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UnitListController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(UnitListController);
public://定义接口
	// 定义分页查询体检单位订单列表接口描述
	ENDPOINT_INFO(queryUnit) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unitreport.order.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//单位名称
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("unitreport.unit.name"),"",false );
		//查找订单签订时间的开始时间
		API_DEF_ADD_QUERY_PARAMS(String, "beginTime", ZH_WORDS_GETTER("unitreport.order.signingTime"), "", false );
		//查找订单签订时间的结束时间
		API_DEF_ADD_QUERY_PARAMS(String, "endTime", ZH_WORDS_GETTER("unitreport.order.signingTime"), "", false );
		//// 定义其他查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}

	// 定义分页查询体检单位订单列表接口
	ENDPOINT(API_M_GET, "/unitreportlist/query-unit", queryUnit, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, UnitPhysicalExaminationOrdersQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryUnit(uq));
	}


private ://定义接口执行函数
	UnitListPageJsonVO::Wrapper execQueryUnit(const UnitPhysicalExaminationOrdersQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif 
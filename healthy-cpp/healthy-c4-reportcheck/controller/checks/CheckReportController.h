#pragma once
#ifndef _REPORTCONTROLLER_H_
#define _REPORTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/checks/CheckReportQuery.h"
#include "domain/vo/checks/CheckReportVO.h"
#include "domain/dto/checks/CheckReportListDTO.h"

/*
* contrller 获取报告列表类
* 负责人Z
*/

// 定义API控制器使用的宏
#include OATPP_CODEGEN_BEGIN(ApiController)

/*
* 接口的实现
* 负责人 Z
*/
class CheckReportController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问接口
	API_ACCESS_DECLARE(CheckReportController);

public://定义接口
	// 定义分页查询接口描述
	ENDPOINT_INFO(queryCheckReport) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("report.get.summary"));
		//定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HENDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		//定义响应参数描述
		API_DEF_ADD_RSP_JSON_WRAPPER(CheckReportListPageJsonVO);
		//定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		// 查询类型
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("report.field.type"), "1", true);
		// 姓名
		API_DEF_ADD_QUERY_PARAMS(String, "person_name", ZH_WORDS_GETTER("report.field.name"), "li ming", false);
		// 订单编号
		API_DEF_ADD_QUERY_PARAMS(String, "order_id", ZH_WORDS_GETTER("report.field.orderId"), "123", false);
		// 体检编号
		API_DEF_ADD_QUERY_PARAMS(String, "test_num", ZH_WORDS_GETTER("report.field.testNum"), "487", false);
		// 单位名称
		API_DEF_ADD_QUERY_PARAMS(String, "unit_id", ZH_WORDS_GETTER("report.field.unitId"), "12", false);
		// 是否过审
		API_DEF_ADD_QUERY_PARAMS(Boolean, "statu", ZH_WORDS_GETTER("report.field.statu"), "1", true);
		// 是否复查
		API_DEF_ADD_QUERY_PARAMS(Boolean, "is_recheck", ZH_WORDS_GETTER("report.field.isRecheck"), "1", true);
		// 开始日期
		API_DEF_ADD_QUERY_PARAMS(String, "stardate", ZH_WORDS_GETTER("report.field.starDate"), "2023-12-17", true);
		// 结束日期
		API_DEF_ADD_QUERY_PARAMS(String, "enddate", ZH_WORDS_GETTER("report.field.endDate"), "2024-1-17", true);
	}
	//定义查询接口处理
	ENDPOINT(API_M_GET, "/checks/query-report", queryCheckReport, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		//解析查询参数为Query领域模型,也就是把查询参数的值解析
		API_HANDLER_QUERY_PARAM(crq, CheckReportQuery, params);
		//呼叫执行函数响应
		API_HANDLER_RESP_VO(execCheckReport(crq));
	}
private://定义接口的执行函数
	CheckReportListPageJsonVO::Wrapper execCheckReport(const CheckReportQuery::Wrapper& query);
};

// 取消API控制器使用宏 
#include OATPP_CODEGEN_END(ApiController)// <- End Codegen
#endif // !_REPORTCONTROLLER_H_

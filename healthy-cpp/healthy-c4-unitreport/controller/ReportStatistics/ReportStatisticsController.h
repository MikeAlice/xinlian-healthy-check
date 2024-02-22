#pragma once

#ifndef _REPORTSTATISTICSCONTROLLER_H_
#define _REPORTSTATISTICSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/ReportStatistics/ReportStatisticsVO.h"
#include "../../domain/query/ReportStatistics/ReportStatisticsQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class PhysicalExaminationPersonnelController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(PhysicalExaminationPersonnelController);
public://定义接口
	// 定义查询体检人员汇总表接口描述
	ENDPOINT_INFO(queryPhysicalExaminationPersonnel) 
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unitreport.summaryTable.PhysicalExaminationPersonnel"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PhysicalExaminationPersonnelJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//订单编号
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("unitreport.order.code"), "", false);
		////统计表类型用数字来表示1："体检人员汇总表" 2："复查人员汇总表" 3："复查结果汇总表"
		//API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("unitreport.summaryTable.type"), 1, true);
		//// 定义其他查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}

	// 定义查询体检人员汇总表接口
	ENDPOINT(API_M_GET, "/ReportStatistics/PhysicalExaminationPersonnel", queryPhysicalExaminationPersonnel, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, ReportStatisticsQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPhysicalExaminationPersonnel(uq));
	}

private://定义接口执行函数
	PhysicalExaminationPersonnelPageJsonVO::Wrapper execQueryPhysicalExaminationPersonnel(const ReportStatisticsQuery::Wrapper& query);

};

class ReviewPersonnelController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(ReviewPersonnelController);
public://定义接口
	// 定义接口描述
	ENDPOINT_INFO(queryReviewPersonnel)
	{
		// 定义查询复查人员汇总表接口描述
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unitreport.summaryTable.ReviewPersonnel"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ReviewPersonnelJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//订单编号
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("unitreport.order.code"), "", false);
		////统计表类型用数字来表示1："体检人员汇总表" 2："复查人员汇总表" 3："复查结果汇总表"
		//API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("unitreport.summaryTable.type"), 2, true);
		//// 定义其他查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}

	// 定义查询复查人员汇总表接口
	ENDPOINT(API_M_GET, "/ReportStatistics/ReviewPersonnel", queryReviewPersonnel, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, ReportStatisticsQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryReviewPersonnel(uq));
	}

private://定义接口执行函数
	ReviewPersonnelPageJsonVO::Wrapper execQueryReviewPersonnel(const  ReportStatisticsQuery::Wrapper& query);

};

class ReviewResultsController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(ReviewResultsController);
public://定义接口
	// 定义查询复查结果汇总表接口描述
	ENDPOINT_INFO(queryReviewResults)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unitreport.summaryTable.ReviewResults"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ReviewResultsJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//订单编号
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("unitreport.order.code"), "", false);
		////统计表类型用数字来表示1："体检人员汇总表" 2："复查人员汇总表" 3："复查结果汇总表"
		//API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("unitreport.summaryTable.type"), 3, true);
		//// 定义其他查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}

	// 定义查询复查结果汇总表接口
	ENDPOINT(API_M_GET, "/ReportStatistics/ReviewResults", queryReviewResults, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, ReportStatisticsQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryReviewResults(uq));
	}

private://定义接口执行函数
	ReviewResultsPageJsonVO::Wrapper execQueryReviewResults(const ReportStatisticsQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif 
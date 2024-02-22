#pragma once
#ifndef _MEDEXAMPRINTREPORT_CONTROLLER_H_
#define _MEDEXAMPRINTREPORT_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/MedExamPrintReportQuery.h"
#include "domain/dto/MedExamPrintReportDTO.h"
#include "domain/vo/MedExamPrintReportVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 获取体检人员查询接口
 * 负责人：小智
 */
class MedExamPrintReportController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(MedExamPrintReportController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryMedExamPrintReport) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("print.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MedExamPrintReportJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述

		// 姓名
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("print.field.name"), "na", false);
		// 体检类型
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("print.field.type"), "", true);
		// 订单编号
		API_DEF_ADD_QUERY_PARAMS(String, "orderId", ZH_WORDS_GETTER("print.field.orderId"), "", false);
		// 体检编号
		API_DEF_ADD_QUERY_PARAMS(String, "testNum", ZH_WORDS_GETTER("print.field.testNum"), "", false);
		// 单位名称
		API_DEF_ADD_QUERY_PARAMS(String, "dept", ZH_WORDS_GETTER("print.field.dept"), "", false);
		// 开始日期
		API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("print.field.startDate"), "", false);
		// 结束日期
		API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("print.field.endDate"), "", false);
		// 是否复查
		API_DEF_ADD_QUERY_PARAMS(Boolean, "isRecheck", ZH_WORDS_GETTER("print.field.isRecheck"), "1", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/medexamprint", queryMedExamPrintReport, QUERIES(QueryParams, params),API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, MedExamPrintReportQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryMedExamPrintReport(uq));
	}

private:
	
	MedExamPrintReportPageJsonVO::Wrapper execQueryMedExamPrintReport(const MedExamPrintReportQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MEDEXAMPRINTREPORT_CONTROLLER_H_
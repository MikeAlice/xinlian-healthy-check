#pragma once
#ifndef _PREVIEWREPORTCONTROLLER_H_
#define _PREVIEWREPORTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/previews/PreviewReportQuery.h"
#include "domain/vo/previews/PreviewReportVO.h"
#include "domain/dto/previews/PreviewReportDTO.h"

// 定义API控制器使用的宏
#include OATPP_CODEGEN_BEGIN(ApiController)

/*
* 接口的实现
* 负责人 Z
*/
class PreviewReportController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问接口
	API_ACCESS_DECLARE(PreviewReportController);

public://定义接口
	// 定义分页查询接口描述
	ENDPOINT_INFO(queryPreviewReport) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("preview.get.summary"));	
		//定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HENDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		//定义响应参数描述
		API_DEF_ADD_RSP_JSON_WRAPPER(PreviewReportJsonVO);
		// 定义其他查询参数描述
		
		// 人员的id
		API_DEF_ADD_QUERY_PARAMS(String, "persionId", ZH_WORDS_GETTER("preview.field.persionid"), nullptr, true);
	}
	//定义查询接口处理
	ENDPOINT(API_M_GET, "/previews/preview-report", queryPreviewReport, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		//解析查询参数为Query领域模型,也就是把查询参数的值解析
		API_HANDLER_QUERY_PARAM(prq, PreviewReportQuery, params);
		//呼叫执行函数响应
		API_HANDLER_RESP_VO(execPreviewReport(prq));
	}
private://定义接口的执行函数
	PreviewReportJsonVO::Wrapper execPreviewReport(const PreviewReportQuery::Wrapper& query);
};

// 取消API控制器使用宏 
#include OATPP_CODEGEN_END(ApiController)// <- End Codegen
#endif // !_PREVIEWREPORTCONTROLLER_H_

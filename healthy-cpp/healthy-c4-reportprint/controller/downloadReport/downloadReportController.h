#pragma once

#ifndef _DOWNLOADREPORT_CONTROLLER_H_
#define _DOWNLOADREPORT_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include <iostream>
#include <utility>

#include "domain/vo/downloadreport/DownloadReportVO.h"

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 报告下载接口
 */
class DownloadReportController  : public oatpp::web::server::api::ApiController 
{
	//  定义控制器访问入口
	API_ACCESS_DECLARE(DownloadReportController);

public:
	// 定义一个文件下载接口
	// 定义描述
	ENDPOINT_INFO(downloadFile) {
		// 定义描述
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("print.get.download"), Void);
		// 待下载的报告编号
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("preview.field.reportNum"), "1202204010001", true);
		// 报告名称设定
		API_DEF_ADD_QUERY_PARAMS(String, "reportName", ZH_WORDS_GETTER("addition.field.reportName"), ZH_WORDS_GETTER("addition.test.testReportName"), false);
	}

	// 定义端点
	ENDPOINT(API_M_GET, "/downloadReport", downloadFile, QUERY(String, reportName)) {
		return execDownloadFile(reportName);
	}

private: // 定义接口执行函数
	// 执行下载处理
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& reportName);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _DOWNLOADREPORT_CONTROLLER_H_
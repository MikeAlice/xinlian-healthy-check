#include "stdafx.h"
#include <iostream>
#include "DownloadReportController.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DownloadReportController::execDownloadFile(const String& reportName)
{
	// 构建PDF报告全路径
	std::string report_fullPath = "public/static/report/sample.pdf" ;

	// 读取PDF报告
	auto report_fstring = String::loadFromFile(report_fullPath.c_str());

	// 判断是否读取成功
	if (!report_fstring)
	{
		std::cerr << "Failed to open report: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "Report Not Found");
	}

	// 创建响应头
	auto report_response = createResponse(Status::CODE_200, report_fstring);

	// 设置响应头信息
	report_response->putHeader("Content-Disposition", "attachment; filename=" + reportName.getValue("") + ".pdf") ;

	// 影响成功结果
	return report_response;
}





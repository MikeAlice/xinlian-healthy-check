#include "stdafx.h"
#include <iostream>
#include "DownloadSampleCodeController.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DownloadSampleCodeController::execDownloadSampleCode(const String& sampleCodeName)
{
	// 构建样本条码全路径
	std::string code_fullPath = "public/static/SampleCode/SampleCode.png";

	// 读取样本条码
	auto code_fstring = String::loadFromFile(code_fullPath.c_str());

	// 判断是否读取成功
	if (!code_fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto code_response = createResponse(Status::CODE_200, code_fstring);

	// 设置响应头信息
	code_response->putHeader("Content-Disposition", "attachment; filename=" + sampleCodeName.getValue("") + ".png");

	// 影响成功结果
	return code_response;
}

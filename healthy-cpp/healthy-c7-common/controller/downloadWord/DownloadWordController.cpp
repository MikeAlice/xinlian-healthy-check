#include "stdafx.h"
#include <iostream>
#include "DownloadWordController.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
// #include "../../service/downloadWord/DownloadWordService.h"




std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DownloadWordController::execDownloadWord(const String& fileUrl)
{
	// 构建文件全路径
	std::string fullPath = "public/static/" + URIUtil::urlDecode(fileUrl.getValue(""));

	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + fileUrl.getValue(""));

	// 影响成功结果
	return response;
}

  
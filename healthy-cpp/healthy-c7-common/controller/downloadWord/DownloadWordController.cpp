#include "stdafx.h"
#include <iostream>
#include "DownloadWordController.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
// #include "../../service/downloadWord/DownloadWordService.h"




std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DownloadWordController::execDownloadWord(const String& fileUrl)
{
	// �����ļ�ȫ·��
	std::string fullPath = "public/static/" + URIUtil::urlDecode(fileUrl.getValue(""));

	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + fileUrl.getValue(""));

	// Ӱ��ɹ����
	return response;
}

  
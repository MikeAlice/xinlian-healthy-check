#include "stdafx.h"
#include <iostream>
#include "DownloadSampleCodeController.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DownloadSampleCodeController::execDownloadSampleCode(const String& sampleCodeName)
{
	// ������������ȫ·��
	std::string code_fullPath = "public/static/SampleCode/SampleCode.png";

	// ��ȡ��������
	auto code_fstring = String::loadFromFile(code_fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!code_fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto code_response = createResponse(Status::CODE_200, code_fstring);

	// ������Ӧͷ��Ϣ
	code_response->putHeader("Content-Disposition", "attachment; filename=" + sampleCodeName.getValue("") + ".png");

	// Ӱ��ɹ����
	return code_response;
}

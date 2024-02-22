#include "stdafx.h"
#include <iostream>
#include "DownloadReportController.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DownloadReportController::execDownloadFile(const String& reportName)
{
	// ����PDF����ȫ·��
	std::string report_fullPath = "public/static/report/sample.pdf" ;

	// ��ȡPDF����
	auto report_fstring = String::loadFromFile(report_fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!report_fstring)
	{
		std::cerr << "Failed to open report: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "Report Not Found");
	}

	// ������Ӧͷ
	auto report_response = createResponse(Status::CODE_200, report_fstring);

	// ������Ӧͷ��Ϣ
	report_response->putHeader("Content-Disposition", "attachment; filename=" + reportName.getValue("") + ".pdf") ;

	// Ӱ��ɹ����
	return report_response;
}





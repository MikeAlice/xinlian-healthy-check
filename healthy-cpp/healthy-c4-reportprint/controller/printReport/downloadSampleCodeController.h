#pragma once

#ifndef _DOWNLOADSAMPLECODE_CONTROLLER_H_
#define _DOWNLOADSAMPLECODE_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include <iostream>
#include <utility>

#include "domain/vo/printreport/DownloadSampleCodeVO.h"

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �������ؽӿ�
 */
class DownloadSampleCodeController : public oatpp::web::server::api::ApiController
{
	//  ����������������
	API_ACCESS_DECLARE(DownloadSampleCodeController);

public:


	// ����һ�����������ȡ�ӿ�
	// ��������
	ENDPOINT_INFO(downloadFile) {
		// �ӿڱ���
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("print.get.sampleCode"), Void);
		// ������
		API_DEF_ADD_QUERY_PARAMS(String, "sampleCodeNum", ZH_WORDS_GETTER("addition.field.sampleCodeNum"), "436591946372", false);
		// ��������
		API_DEF_ADD_QUERY_PARAMS(String, "sampleCodeName", ZH_WORDS_GETTER("addition.field.sampleCodeName"), ZH_WORDS_GETTER("addition.test.sampleCodeName"), false);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/downloadSampleCode", downloadFile, QUERY(String, sampleCodeName)) {
		return execDownloadSampleCode(sampleCodeName);
	}

private: // ����ӿ�ִ�к���
	// ��ȡ��������
	std::shared_ptr<OutgoingResponse> execDownloadSampleCode(const String& sampleCodeName);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _DOWNLOADSAMPLECODE_CONTROLLER_H_
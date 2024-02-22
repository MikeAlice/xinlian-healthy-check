#pragma once
 
#ifndef _DOWNLOADWORDCONTROLLER_H_
#define _DOWNLOADWORDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
// #include "domain/vo/file/FileVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class DownloadWordController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(DownloadWordController);
public:
	// ����һ���ļ����ؽӿ�
	// ��������
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("wordFile.download.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "fileUrl", ZH_WORDS_GETTER("wordFile.field.fileUrl"), "file/1.docx", true);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/healthy-c7-common/download-word", downloadFile, QUERY(String, fileUrl)) {
		return execDownloadWord(fileUrl);
	}
 private: // ����ӿ�ִ�к���
 
	// ִ���ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadWord(const String& fileUrl);
 
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_
#pragma once
 
#ifndef _DOWNLOADWORDCONTROLLER_H_
#define _DOWNLOADWORDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
// #include "domain/vo/file/FileVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作示例接口
 */
class DownloadWordController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(DownloadWordController);
public:
	// 定义一个文件下载接口
	// 定义描述
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("wordFile.download.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "fileUrl", ZH_WORDS_GETTER("wordFile.field.fileUrl"), "file/1.docx", true);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/healthy-c7-common/download-word", downloadFile, QUERY(String, fileUrl)) {
		return execDownloadWord(fileUrl);
	}
 private: // 定义接口执行函数
 
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadWord(const String& fileUrl);
 
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_
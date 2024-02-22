#ifndef _FILECONTROLLER_H_
#define _FILECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/Exalanding/FileVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作示例接口
 */
class FileController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(FileController);
public:
	// 定义一个单文件上传接口
	// 定义描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("exalanding.file.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT(API_M_POST, "Exalanding/uploadimage", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));

private: // 定义接口执行函数
	// 执行单文件上传处理
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_
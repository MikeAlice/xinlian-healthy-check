#pragma once
#ifndef _PICCONTROLLER_H_
#define _PICCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/Pic/PicVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作示例接口
 */
class PicController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(PicController);
public:
	// 定义一个文件上传接口用于处理富文本编辑器
	// 定义描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.editor-upload-image.summary"), uploadImage, PicImageVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT(API_M_POST, "/Pic/Pic-upload-image", uploadImage, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadPicImage(request));
private: // 定义接口执行函数
	// 执行Editor图片上传处理
	PicImageVO::Wrapper execUploadPicImage(std::shared_ptr<IncomingRequest> request);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_
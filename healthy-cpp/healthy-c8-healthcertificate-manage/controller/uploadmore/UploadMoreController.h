#pragma once
#ifndef _UPLOADMORECONTROLLER_
#define _UPLOADMORECONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/uploadmore/UploadMoreDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 健康证批量上传控制器
 */
class UploadMoreController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义批量上传控制器访问入口
	API_ACCESS_DECLARE(UploadMoreController);
	// 3 定义接口
public:
	// 3.1 定义批量上传接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("uploadmore.post.summary"), uploadHealthcertificateMore, Uint64JsonVO::Wrapper);
	// 3.2 定义批量上传接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/healthcertificate-manage/upload-healthcertificates", uploadHealthcertificateMore, BODY_DTO(List<UploadMoreDTO::Wrapper>, dtoArray), execUploadHealthCertificates(dtoArray));
private:
	// 3.3 批量上传
	StringJsonVO::Wrapper execUploadHealthCertificates(const List<UploadMoreDTO::Wrapper>& dtoArray);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif 
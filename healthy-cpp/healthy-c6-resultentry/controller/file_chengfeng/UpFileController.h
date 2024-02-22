#pragma once

#ifndef _UP_FILE_CONTROLLER_
#define _UP_FILE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/dto/file_chengfeng/UpFileDTO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 控制器，修改接口
 */
class UpFileController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(UpFileController);
	// 3 定义接口
public:
	
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("file_chengfeng.upload.summary"), modifySample, StringJsonVO::Wrapper);
	
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/resultentry/filexxx/uploadxxx", modifySample, BODY_DTO(UpFileDTO::Wrapper, dto), execModifySample(dto, authObject->getPayload()));


private:	
	// 3.3 修改数据
	StringJsonVO::Wrapper execModifySample(const UpFileDTO::Wrapper& dto, const PayloadDTO& payload);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_UP_FILE_CONTROLLER_
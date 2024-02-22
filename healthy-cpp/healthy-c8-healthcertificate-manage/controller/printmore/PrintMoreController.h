#pragma once
#ifndef _PRINTMORE_CONTROLLER_
#define _PRINTMORE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/printmore/PrintMoreDTO.h"
#include "domain/vo/printmore/PrintMoreVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

class PrintMoreController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PrintMoreController);
	// 3 定义接口
public:
	// 3.1 定义下载接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("printmore.download-printmore.summary"), downloadPrintMore, ResultJsonVO::Wrapper);
	// 3.2 定义下载接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/healthcertificate-manage/download-printmore", downloadPrintMore, BODY_DTO(List<PrintMoreDTO::Wrapper>, dto), execDownloadPrintMore(dto));
private:
	ResultJsonVO::Wrapper execDownloadPrintMore(const List<PrintMoreDTO::Wrapper>& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRINTMORE_CONTROLLER_
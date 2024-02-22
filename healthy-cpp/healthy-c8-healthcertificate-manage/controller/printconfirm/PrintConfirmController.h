#pragma once
#ifndef _PrintConfirmController_
#define _PrintConfirmController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/printconfirm/PrintConfirmDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class PrintConfirmController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PrintConfirmController);
	// 3 定义接口
public:
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("printconfirm.put.summary"), modifyPrintConfirm, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/healthcertificate-manage/modify-printconfirm", modifyPrintConfirm, BODY_DTO(List<String>, dto), execModifyPrintConfirm(dto));
private:
	// 3.3 演示修改数据
	StringJsonVO::Wrapper execModifyPrintConfirm(const List<String>& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
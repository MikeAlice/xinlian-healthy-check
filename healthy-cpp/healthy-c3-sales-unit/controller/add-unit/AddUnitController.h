#pragma once

#ifndef _ADDUNITCONTROLLER_H_
#define _ADDUNITCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/update-unit/UnitDetailDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 新增单位    负责人：duxlong
 */
class AddUnitController: public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AddUnitController);
public: // 3 定义接口
// 	// 3.1 定义接口描述
// 	// 3.2 定义接口处理
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unit.post.summary"), add, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/sales/unit/add", add, BODY_DTO(UnitDetailDTO::Wrapper, dto), execAddUnit(dto, authObject->getPayload()));

private: // 3.3 定义接口执行函数
	StringJsonVO::Wrapper execAddUnit(const UnitDetailDTO::Wrapper& dto, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_ADDUNITCONTROLLER_H_

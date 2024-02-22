#pragma once

#ifndef _MODIFYUNITCONTROLLER_H_
#define _MODIFYUNITCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/update-unit/UnitDetailDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ModifyUnitController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ModifyUnitController);

public: // 3 定义接口
// 	// 3.1 定义接口描述
// 	// 3.2 定义接口处理

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unit.put.summary"), modifyUnit, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/sales/unit/update", modifyUnit, BODY_DTO(UnitDetailDTO::Wrapper, dto), execModifyUnit(dto, authObject->getPayload()));

private: // 定义接口执行函数
	//前端→UnitDetailDTO→后端→Uint64JsonVO→前端
	StringJsonVO::Wrapper execModifyUnit(const UnitDetailDTO::Wrapper& dto, const PayloadDTO& payload);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_MODIFYUNITCONTROLLER_H_


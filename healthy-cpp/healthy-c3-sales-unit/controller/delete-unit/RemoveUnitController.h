#pragma once

#ifndef _REMOVEUNITCONTROLLER_H_
#define _REMOVEUNITCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/delete-unit/RemoveUnitDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 删除单位（支持批量删除）    负责人：罗浩巍
 */
class RemoveUnitController: public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(RemoveUnitController);
public: // 3 定义接口

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unit.delete.summary"), removeUnit, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sales/unit/delete", removeUnit, BODY_DTO(List<RemoveUnitDTO::Wrapper>, dto), execRemoveUnit(dto, authObject->getPayload()));
/*
BODY_DTO示例
[
  {
	"id": "xxx"
  },
  {
	"id": "xxxxx"
  }
]
*/
private: // 3.3 定义接口执行函数
	// 删除数据
	StringJsonVO::Wrapper execRemoveUnit(const List<RemoveUnitDTO::Wrapper>& dto, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_REMOVEUNITCONTROLLER_H_

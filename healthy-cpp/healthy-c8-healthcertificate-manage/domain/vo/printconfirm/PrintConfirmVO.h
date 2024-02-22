#pragma once
#ifndef _PRINTCONFIRMVO_H_
#define _PRINTCONFIRMVO_H_

#include "../../GlobalInclude.h"
#include"../../dto/printconfirm/PrintConfirmDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 打印确认显示JsonVO实体，用于响应给客户端的Json对象
 */
class PrintConfirmJsonVO : public JsonVO<PrintConfirmDTO::Wrapper> {
	DTO_INIT(PrintConfirmJsonVO, JsonVO<PrintConfirmDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PRINTCONFIRMVO_H_

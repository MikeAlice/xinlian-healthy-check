#pragma once
#ifndef _INTERRO_VO_
#define _INTERRO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/interro/InterroDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class InterroJsonVO : public JsonVO<oatpp::List<InterroDTO::Wrapper>> {
	DTO_INIT(InterroJsonVO, JsonVO<oatpp::List<InterroDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_INTERRO_VO_
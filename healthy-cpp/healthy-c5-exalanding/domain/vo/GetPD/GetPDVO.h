#pragma once
#ifndef _GetPD_VO_
#define _GetPD_VO_

#include "../../GlobalInclude.h"
#include "../../dto/GetPD/GetPDDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class GetPDJsonVO : public JsonVO<GetPDDTO::Wrapper> {
	DTO_INIT(GetPDJsonVO, JsonVO<GetPDDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class GetPDPageJsonVO : public JsonVO<GetPDPageDTO::Wrapper> {
	DTO_INIT(GetPDPageJsonVO, JsonVO<GetPDPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GetPD_VO_
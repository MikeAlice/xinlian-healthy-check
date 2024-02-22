#pragma once
#ifndef _UserNameListVO_
#define _UserNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/usernamelist/UserNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class UserNameListJsonVO : public JsonVO<UserNameListDTO::Wrapper> {
	DTO_INIT(UserNameListJsonVO, JsonVO<UserNameListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
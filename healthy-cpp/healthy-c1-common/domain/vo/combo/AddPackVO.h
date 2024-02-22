#ifndef _ADDPACKVO_H_
#define _ADDPACKVO_H_


#include "../../GlobalInclude.h"
#include "../../dto/combo/AddPackDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个用户信息显示JsonVO对象，用于响应给客户端
 */
class AddPackJsonVO : public JsonVO<AddPackDTO::Wrapper>
{
	DTO_INIT(AddPackJsonVO, JsonVO<AddPackDTO::Wrapper>);
};

/**
 * 定义一个用户信息分页显示JsonVO对象，用于响应给客户端
 */
class AddPackPageJsonVO : public JsonVO<AddPackPageDTO::Wrapper>
{
	DTO_INIT(AddPackPageJsonVO, JsonVO<AddPackPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDPACKVO_H_
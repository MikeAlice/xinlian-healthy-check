#ifndef _DELPACKVO_H_
#define _DELPACKVO_H_


#include "../../GlobalInclude.h"
#include "../../dto/combo/DelPackDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个用户信息显示JsonVO对象，用于响应给客户端
 */
class DelPackJsonVO : public JsonVO<DelPackDTO::Wrapper>
{
	DTO_INIT(DelPackJsonVO, JsonVO<DelPackDTO::Wrapper>);
};

/**
 * 定义一个用户信息分页显示JsonVO对象，用于响应给客户端
 */
class DelPackPageJsonVO : public JsonVO<DelPackPageDTO::Wrapper>
{
	DTO_INIT(DelPackPageJsonVO, JsonVO<DelPackPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DELPACKVO_H_
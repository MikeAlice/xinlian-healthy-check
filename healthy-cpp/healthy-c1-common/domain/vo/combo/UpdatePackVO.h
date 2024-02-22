#ifndef _UPDATEPACKVO_H_
#define _UPDATEPACKVO_H_


#include "../../GlobalInclude.h"
#include "../../dto/combo/UpdatePackDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个用户信息显示JsonVO对象，用于响应给客户端
 */
class UpdatePackJsonVO : public JsonVO<UpdatePackDTO::Wrapper>
{
	DTO_INIT(UpdatePackJsonVO, JsonVO<UpdatePackDTO::Wrapper>);
};

/**
 * 定义一个用户信息分页显示JsonVO对象，用于响应给客户端
 */
class UpdatePackPageJsonVO : public JsonVO<UpdatePackPageDTO::Wrapper>
{
	DTO_INIT(UpdatePackPageJsonVO, JsonVO<UpdatePackPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UPDATEPACKVO_H_
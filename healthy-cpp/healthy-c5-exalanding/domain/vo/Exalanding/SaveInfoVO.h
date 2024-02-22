#pragma once
#ifndef _SAVE_INFO_VO_H_
#define _SAVE_INFO_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Exalanding/SaveInfoDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个用户信息显示JsonVO对象，用于响应给客户端
 */
class SaveInfoJsonVO : public JsonVO<SaveInfoDTO::Wrapper>
{
	DTO_INIT(SaveInfoJsonVO, JsonVO<SaveInfoDTO::Wrapper>);
};

/**
 * 定义一个用户信息分页显示JsonVO对象，用于响应给客户端
 */
class SaveInfoPageJsonVO : public JsonVO<SaveInfoPageDTO::Wrapper>
{
	DTO_INIT(SaveInfoPageJsonVO, JsonVO<SaveInfoPageDTO::Wrapper>);
};



#endif // _SAVE_INFO_VO_H_
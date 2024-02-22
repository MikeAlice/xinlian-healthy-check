#pragma once


#ifndef _DOWNVO_H_
#define _DOWNVO_H_

#include "../../GlobalInclude.h"
#include "../../domain/dto/download-entrust-template/DownDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)


class DownJsonVO : public JsonVO<DownDTO::Wrapper>
{
	DTO_INIT(DownJsonVO, JsonVO<DownDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_
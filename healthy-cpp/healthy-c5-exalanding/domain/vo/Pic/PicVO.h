#pragma once

#ifndef _PICVO_H_
#define _PICVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Pic/PicDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PicImageVO : public JsonVO<PicImageDTO::Wrapper>
{
	DTO_INIT(PicImageVO, JsonVO<PicImageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEVO_H_
#pragma once
#ifndef _SampleJsonVO_H_`
#define _SampleJsonVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/bas/SampleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//单位列表显示jsonVO实体
class SampleJsonVO : public JsonVO <SampleDTO::Wrapper>
{
	DTO_INIT(SampleJsonVO, JsonVO <SampleDTO::Wrapper>);
};




#include OATPP_CODEGEN_END(DTO)

#endif
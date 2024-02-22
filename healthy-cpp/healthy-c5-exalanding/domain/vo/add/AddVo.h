#pragma once
#ifndef _ADDVO_H_
#define _ADDVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/add/AddUnitDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//单位列表显示jsonVO实体            
class AddJsonVO :public JsonVO<AddUnitDTO::Wrapper>
{
	DTO_INIT(AddJsonVO, JsonVO<AddUnitDTO::Wrapper>);
	//查询类型
};
//单位列表显示分页jsonvo实体
class AddPageJsonVO : public JsonVO<AddPageDTO::Wrapper>
{
	DTO_INIT(AddPageJsonVO, JsonVO<AddPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif

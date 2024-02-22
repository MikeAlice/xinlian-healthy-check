#pragma once
#ifndef _ADDVO_H_
#define _ADDVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/add/AddUnitDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//��λ�б���ʾjsonVOʵ��            
class AddJsonVO :public JsonVO<AddUnitDTO::Wrapper>
{
	DTO_INIT(AddJsonVO, JsonVO<AddUnitDTO::Wrapper>);
	//��ѯ����
};
//��λ�б���ʾ��ҳjsonvoʵ��
class AddPageJsonVO : public JsonVO<AddPageDTO::Wrapper>
{
	DTO_INIT(AddPageJsonVO, JsonVO<AddPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif

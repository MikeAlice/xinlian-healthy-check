#pragma once
#ifndef _CHECKLISTDTO_H_
#define _CHECKLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CheckListDTO : public oatpp::DTO
{
	DTO_INIT(CheckListDTO, DTO);
	//项目名称（不确定写对没，先用了数据库t_lis里的“类型”，item。）
	API_DTO_FIELD_DEFAULT(String, item, ZH_WORDS_GETTER("check.field.item"));
	//原价
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("check.field.id_card"));
	//折扣
	API_DTO_FIELD_DEFAULT(UInt32, discount, ZH_WORDS_GETTER("check.field.discount"));
	//折扣价
	API_DTO_FIELD_DEFAULT(Float64, discount_price, ZH_WORDS_GETTER("check.field.discount_price"));
	//项目类型
	API_DTO_FIELD_DEFAULT(String, physical_type, ZH_WORDS_GETTER("check.field.physical_type"));

};

/**
 * 体检人员名称列表分页传输对象
 */
class CheckListPageDTO : public PageDTO<CheckListDTO::Wrapper>
{
	DTO_INIT(CheckListPageDTO, PageDTO<CheckListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CHECKLISTDTO_H_
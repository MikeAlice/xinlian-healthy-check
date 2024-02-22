#pragma once

#ifndef _DELPACKDTO_H_
#define _DELPACKDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DelPackDTO : public oatpp::DTO
{
	DTO_INIT(DelPackDTO, DTO);

	// id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("combo.field.id"));

};

/**
 * 定义一个用户信息分页传输对象
 */
class DelPackPageDTO : public PageDTO<DelPackDTO::Wrapper>
{
	DTO_INIT(DelPackPageDTO, PageDTO<DelPackDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !DELPACKDTO_H

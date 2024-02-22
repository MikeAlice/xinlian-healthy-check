#pragma once

#ifndef _PERSONDTO_H_
#define _PERSONDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个基础项目体检结果的数据传输模型
 */
class PersonDTO : public oatpp::DTO
{
	DTO_INIT(PersonDTO, DTO);
	//组合项目编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("checkitem.portfolio.id"));
	//组合项目名称
	API_DTO_FIELD_DEFAULT(String, portfolioName, ZH_WORDS_GETTER("checkitem.portfolio.name"));
};

class PersonPageDTO : public PageDTO<PersonDTO::Wrapper>{
	DTO_INIT(PersonPageDTO, PageDTO<PersonDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSONDTO_H_


#pragma once
#ifndef _ADDNEWITEMSDTO_H_
#define _ADDNEWITEMSDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
*  新增复查项目传输数据对象实体
*/
class AddNewItemsDTO : public oatpp::DTO
{
	DTO_INIT(AddNewItemsDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("addNewItems.field.id"));
	//复查项目id
	API_DTO_FIELD_DEFAULT(String, checkProjectId, ZH_WORDS_GETTER("addNewItems.field.checkProjectId"));
	//复查项目名称
	API_DTO_FIELD_DEFAULT(String, checkProjectName, ZH_WORDS_GETTER("addNewItems.field.checkProjectName"));
	//组合项目id
	API_DTO_FIELD_DEFAULT(String, portfolioProjectId, ZH_WORDS_GETTER("addNewItems.field.portfolioProjectId"));
	//组合项目名称
	API_DTO_FIELD_DEFAULT(String, portfolioProjectName, ZH_WORDS_GETTER("addNewItems.field.portfolioProjectName"));
	//复查原因
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("addNewItems.field.reason"));
};

/**
*  新增复查项目分页数据实体
*/
class AddNewItemsPageDTO : public PageDTO<AddNewItemsDTO::Wrapper> {
	DTO_INIT(AddNewItemsPageDTO, PageDTO<AddNewItemsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADDNEWITEMSDTO_H_
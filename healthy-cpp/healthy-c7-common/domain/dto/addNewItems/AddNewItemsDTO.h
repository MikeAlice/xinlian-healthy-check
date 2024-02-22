#pragma once
#ifndef _ADDNEWITEMSDTO_H_
#define _ADDNEWITEMSDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
*  ����������Ŀ�������ݶ���ʵ��
*/
class AddNewItemsDTO : public oatpp::DTO
{
	DTO_INIT(AddNewItemsDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("addNewItems.field.id"));
	//������Ŀid
	API_DTO_FIELD_DEFAULT(String, checkProjectId, ZH_WORDS_GETTER("addNewItems.field.checkProjectId"));
	//������Ŀ����
	API_DTO_FIELD_DEFAULT(String, checkProjectName, ZH_WORDS_GETTER("addNewItems.field.checkProjectName"));
	//�����Ŀid
	API_DTO_FIELD_DEFAULT(String, portfolioProjectId, ZH_WORDS_GETTER("addNewItems.field.portfolioProjectId"));
	//�����Ŀ����
	API_DTO_FIELD_DEFAULT(String, portfolioProjectName, ZH_WORDS_GETTER("addNewItems.field.portfolioProjectName"));
	//����ԭ��
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("addNewItems.field.reason"));
};

/**
*  ����������Ŀ��ҳ����ʵ��
*/
class AddNewItemsPageDTO : public PageDTO<AddNewItemsDTO::Wrapper> {
	DTO_INIT(AddNewItemsPageDTO, PageDTO<AddNewItemsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADDNEWITEMSDTO_H_
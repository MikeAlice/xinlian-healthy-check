#pragma once
#ifndef _ADDNEWITEMSQuery_H_
#define _ADDNEWITEMSQuery_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  ���������¼ʵ��
*/
class AddNewItemsQuery : public PageQuery {
	DTO_INIT(AddNewItemsQuery, PageQuery);
	//��t_review_record
	//������Ŀid check_project_id varchar(50)
	API_DTO_FIELD_DEFAULT(String, checkProjectId, ZH_WORDS_GETTER("addNewItems.field.checkProjectId"));
	//������Ŀ���� check_project_name varchar(255)
	API_DTO_FIELD_DEFAULT(String, checkProjectName, ZH_WORDS_GETTER("addNewItems.field.checkProjectName"));
	//��t_review_project
	//�����Ŀid portfolio_project_id varchar(50)
	API_DTO_FIELD_DEFAULT(String, portfolioProjectId, ZH_WORDS_GETTER("addNewItems.field.portfolioProjectId"));
	//�����Ŀ���� portfolio_project_name varchar(50)
	API_DTO_FIELD_DEFAULT(String, portfolioProjectName, ZH_WORDS_GETTER("addNewItems.field.portfolioProjectName"));
	//����ԭ�� reason varchar(500)
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("addNewItems.field.reason"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADDNEWITEMSQUERY_H_
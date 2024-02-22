#pragma once
#ifndef _ADDNEWITEMSQuery_H_
#define _ADDNEWITEMSQuery_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  新增复查记录实体
*/
class AddNewItemsQuery : public PageQuery {
	DTO_INIT(AddNewItemsQuery, PageQuery);
	//表t_review_record
	//复查项目id check_project_id varchar(50)
	API_DTO_FIELD_DEFAULT(String, checkProjectId, ZH_WORDS_GETTER("addNewItems.field.checkProjectId"));
	//复查项目名称 check_project_name varchar(255)
	API_DTO_FIELD_DEFAULT(String, checkProjectName, ZH_WORDS_GETTER("addNewItems.field.checkProjectName"));
	//表t_review_project
	//组合项目id portfolio_project_id varchar(50)
	API_DTO_FIELD_DEFAULT(String, portfolioProjectId, ZH_WORDS_GETTER("addNewItems.field.portfolioProjectId"));
	//组合项目名称 portfolio_project_name varchar(50)
	API_DTO_FIELD_DEFAULT(String, portfolioProjectName, ZH_WORDS_GETTER("addNewItems.field.portfolioProjectName"));
	//复查原因 reason varchar(500)
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("addNewItems.field.reason"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADDNEWITEMSQUERY_H_
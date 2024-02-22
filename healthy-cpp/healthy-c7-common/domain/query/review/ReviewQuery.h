#pragma once
#ifndef _REVIEWQUERY_H_
#define _REVIEWQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  复查记录分页查询实体
*/
class ReviewQuery : public PageQuery {
	DTO_INIT(ReviewQuery, PageQuery);
	//唯一编号 id varchar(50)
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("review.field.id"));
	//姓名 person_id varchar(50)    t_review_person中有person_name
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("review.field.personName"));
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("review.field.personId"));
	//复查项目check_project_id varchar(50)   check_project_name varchar(255)
	API_DTO_FIELD_DEFAULT(String, checkProjectId, ZH_WORDS_GETTER("review.field.checkProjectId"));
	API_DTO_FIELD_DEFAULT(String, checkProjectName, ZH_WORDS_GETTER("review.field.checkProjectName"));
	//复查说明review_explain varchar(255)
	API_DTO_FIELD_DEFAULT(String, reviewExplain, ZH_WORDS_GETTER("review.field.reviewExplain"));
	//操作日期review_time` datetime '复查日期'
	API_DTO_FIELD_DEFAULT(String, reviewTime, ZH_WORDS_GETTER("review.field.reviewTime"));
	//登记日期create_time datetime '创建日期',
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("review.field.createTime"));
	//登记状态state int '审核状态
	API_DTO_FIELD_DEFAULT(UInt32, state, ZH_WORDS_GETTER("review.field.state"));
	//危害因素hazard_factor_code varchar(255)   t_review_person中有hazard_factor_code
	API_DTO_FIELD_DEFAULT(String, hazardFactorCode, ZH_WORDS_GETTER("review.field.hazardFactorCode"));
	//操作

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REVIEWQUERY_H_
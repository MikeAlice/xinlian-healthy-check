#pragma once
#ifndef _REVIEWListDTO_H_
#define _REVIEWListDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
*  复查记录列表传输数据对象实体
*/
class ReviewListDTO : public oatpp::DTO
{
	DTO_INIT(ReviewListDTO, DTO);
	//唯一编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("review.field.id"));
	//姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("review.field.personName"));
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("review.field.personId"));
	//复查项目check_project_id varchar(50)
	API_DTO_FIELD_DEFAULT(String, checkProjectId, ZH_WORDS_GETTER("review.field.checkProjectId"));
	API_DTO_FIELD_DEFAULT(String, checkProjectName, ZH_WORDS_GETTER("review.field.checkProjectName"));
	//复查说明review_explain varchar(255)
	API_DTO_FIELD_DEFAULT(String, reviewExplain, ZH_WORDS_GETTER("review.field.reviewExplain"));
	//操作日期review_time` datetime '复查日期'
	API_DTO_FIELD_DEFAULT(String, reviewTime, ZH_WORDS_GETTER("review.field.reviewTime"));
	//登记日期create_time datetime '创建日期'
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("review.field.createTime"));
	//登记状态state int '审核状态
	API_DTO_FIELD_DEFAULT(UInt32, state, ZH_WORDS_GETTER("review.field.state"));
	//危害因素hazard_factor_code varchar(255)
	API_DTO_FIELD_DEFAULT(String, hazardFactorCode, ZH_WORDS_GETTER("review.field.hazardFactorCode"));
	//操作

	//pdf downloadUrl
	API_DTO_FIELD_DEFAULT(String, downloadUrl, ZH_WORDS_GETTER("review.field.pdfDownloadUrl"));
};

/**
*  复查列表分页数据实体
*/
class ReviewListPageDTO : public PageDTO<ReviewListDTO::Wrapper> {
	DTO_INIT(ReviewListPageDTO, PageDTO<ReviewListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REVIEWListDTO_H_
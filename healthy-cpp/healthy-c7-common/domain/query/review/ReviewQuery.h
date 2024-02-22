#pragma once
#ifndef _REVIEWQUERY_H_
#define _REVIEWQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  �����¼��ҳ��ѯʵ��
*/
class ReviewQuery : public PageQuery {
	DTO_INIT(ReviewQuery, PageQuery);
	//Ψһ��� id varchar(50)
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("review.field.id"));
	//���� person_id varchar(50)    t_review_person����person_name
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("review.field.personName"));
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("review.field.personId"));
	//������Ŀcheck_project_id varchar(50)   check_project_name varchar(255)
	API_DTO_FIELD_DEFAULT(String, checkProjectId, ZH_WORDS_GETTER("review.field.checkProjectId"));
	API_DTO_FIELD_DEFAULT(String, checkProjectName, ZH_WORDS_GETTER("review.field.checkProjectName"));
	//����˵��review_explain varchar(255)
	API_DTO_FIELD_DEFAULT(String, reviewExplain, ZH_WORDS_GETTER("review.field.reviewExplain"));
	//��������review_time` datetime '��������'
	API_DTO_FIELD_DEFAULT(String, reviewTime, ZH_WORDS_GETTER("review.field.reviewTime"));
	//�Ǽ�����create_time datetime '��������',
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("review.field.createTime"));
	//�Ǽ�״̬state int '���״̬
	API_DTO_FIELD_DEFAULT(UInt32, state, ZH_WORDS_GETTER("review.field.state"));
	//Σ������hazard_factor_code varchar(255)   t_review_person����hazard_factor_code
	API_DTO_FIELD_DEFAULT(String, hazardFactorCode, ZH_WORDS_GETTER("review.field.hazardFactorCode"));
	//����

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REVIEWQUERY_H_
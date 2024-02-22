#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: c1-pepper
 @Date: 2024/1/15

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _RULESLISTQUERY_H_
#define _RULESLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡָ����Ŀָ����������
 */
class RulesListQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(RulesListQuery, PageQuery);
	// ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("rules.field.id"));
	//// name����
	//API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("rules.field.name"));
	//// shortname���
	//API_DTO_FIELD_DEFAULT(String, short_name, ZH_WORDS_GETTER("rules.field.short_name"));
	//// type����
	//API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("rules.field.type"));
	//// allowSex�ʺ��Ա�
	//API_DTO_FIELD_DEFAULT(String, allow_Sex, ZH_WORDS_GETTER("rules.field.allow_Sex"));
	//// baseProjectId��ĿID
	//API_DTO_FIELD_DEFAULT(String, base_project_id, ZH_WORDS_GETTER("rules.field.base_project_id"));
	//// careerAdviceְҵ����
	//API_DTO_FIELD_DEFAULT(String, career_advice, ZH_WORDS_GETTER("rules.field.caree_advice"));
	//// createId������
	//API_DTO_FIELD_DEFAULT(String, create_id, ZH_WORDS_GETTER("rules.field.create_id"));
	//// createTime����ʱ��
	//API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("rules.field.create_time"));
	//// departmentId��������
	//API_DTO_FIELD_DEFAULT(String, department_id, ZH_WORDS_GETTER("rules.field.department_id"));
	//// dietaryGuidance��ʳָ��
	//API_DTO_FIELD_DEFAULT(String, dietary_guidance, ZH_WORDS_GETTER("rules.field.dietary_guidance"));
	//// healthAdvice��������
	//API_DTO_FIELD_DEFAULT(String, health_advice, ZH_WORDS_GETTER("rules.field.health_advice"));

	//// healthKnowledge����֪ʶ
	//API_DTO_FIELD_DEFAULT(String, health_knowledge, ZH_WORDS_GETTER("rules.field.health_knowledge"));
	//// inConclusion�Ƿ����С��
	//API_DTO_FIELD_DEFAULT(String, in_conclusion, ZH_WORDS_GETTER("rules.field.in_conclusion"));
	//// intervalValue����ֵ
	//API_DTO_FIELD_DEFAULT(String, interval_value, ZH_WORDS_GETTER("rules.field.interval_value"));
	//// maxAge�������ֵ
	//API_DTO_FIELD_DEFAULT(Int32, max_Age, ZH_WORDS_GETTER("rules.field.max_Age"));
	//// minAge�������ֵ
	//API_DTO_FIELD_DEFAULT(Int32, min_Age, ZH_WORDS_GETTER("rules.field.min_Age"));
	//// positive�Ƿ�����
	//API_DTO_FIELD_DEFAULT(String, positive, ZH_WORDS_GETTER("rules.field.positive"));
	//// reminder��ܰ��ʾ
	//API_DTO_FIELD_DEFAULT(String, reminder, ZH_WORDS_GETTER("rules.field.reminder"));
	//// sportsGuidance�˶�ָ��
	//API_DTO_FIELD_DEFAULT(String, sports_guidance, ZH_WORDS_GETTER("rules.field.sports_guidance"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RULESLISTQUERY_H_
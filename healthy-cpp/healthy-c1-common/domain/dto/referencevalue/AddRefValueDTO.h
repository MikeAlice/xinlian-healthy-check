#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2024/01/13
 @FileName: AddRefValueDTO
 @version: 1.0

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
#ifndef _ADD_REF_VALUE_DTO_
#define _ADD_REF_VALUE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddRefValueDTO : public oatpp::DTO
{
	DTO_INIT(AddRefValueDTO, DTO);
	// id ����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("common.reference_value.field.id"));
	// base_project_id ��Ŀid
	API_DTO_FIELD_DEFAULT(String, base_project_id, ZH_WORDS_GETTER("common.reference_value.field.base_project_id"));
	// allow_sex �ʺ��Ա�
	API_DTO_FIELD_DEFAULT(String, allow_sex, ZH_WORDS_GETTER("common.reference_value.field.allow_sex"));
	// min_age �������ֵ
	API_DTO_FIELD_DEFAULT(Int64, min_age, ZH_WORDS_GETTER("common.reference_value.field.min_age"));
	// max_age �������ֵ
	API_DTO_FIELD_DEFAULT(Int64, max_age, ZH_WORDS_GETTER("common.reference_value.field.max_age"));
	// healthy_value �����ο�ֵ
	API_DTO_FIELD_DEFAULT(String, healthy_value, ZH_WORDS_GETTER("common.reference_value.field.healthy_value"));
	// occupation_value ְҵ�ο�ֵ
	API_DTO_FIELD_DEFAULT(String, occupation_value, ZH_WORDS_GETTER("common.reference_value.field.occupation_value"));
	// department_id ��������
	API_DTO_FIELD_DEFAULT(String, department_id, ZH_WORDS_GETTER("common.reference_value.department_id"));
	// create_id ������
	API_DTO_FIELD_DEFAULT(String, create_id, ZH_WORDS_GETTER("common.reference_value.field.create_id"));
	// create_time ����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("common.reference_value.field.create_time"));

};

#include OATPP_CODEGEN_END(DTO)
#endif
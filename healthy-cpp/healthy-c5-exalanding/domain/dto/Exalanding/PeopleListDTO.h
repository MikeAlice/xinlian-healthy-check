#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: duifang
 @Date: 2024/1/17 11:36:29

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
#ifndef _PEOPLELISTDTO_H_
#define _PEOPLELISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����Ա�����б��ҳ���ݴ���ģ��
 */
class PeopleListDTO : public oatpp::DTO
{
	DTO_INIT(PeopleListDTO, DTO);
	// Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("Exalanding.field.id"));
	// ����
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("Exalanding.field.person_name"));
	// �Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("Exalanding.field.sex"));
	// ����
    API_DTO_FIELD_DEFAULT(Int32, age, ZH_WORDS_GETTER("Exalanding.field.age"));
	// �������
	API_DTO_FIELD_DEFAULT(String, jc_type, ZH_WORDS_GETTER("Exalanding.field.jc_type"));
	// �Ƿ��������
	API_DTO_FIELD_DEFAULT(String, sporadic_physical, ZH_WORDS_GETTER("Exalanding.field.sporadic_physical"));
};

/**
 * �����Ա�����б��ҳ�������
 */
class PeopleListPageDTO : public PageDTO<PeopleListDTO::Wrapper>
{
	DTO_INIT(PeopleListPageDTO, PageDTO<PeopleListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
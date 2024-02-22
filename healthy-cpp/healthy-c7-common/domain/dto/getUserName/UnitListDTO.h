#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _UnitListDTO_H_
#define _UnitListDTO_H_

#include "../../GlobalInclude.h" 

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* ��λ�б������ݶ���ʵ��
*/
class UnitListDTO : public oatpp::DTO
{
	DTO_INIT(UnitListDTO, DTO);
	//����
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("getUserName.field.personName"));
	//�Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("getUserName.field.sex"));
	// ����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("getUserName.field.age"));
	//������� physicalType
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("getUserName.field.physicalType"));
	//�Ƿ��������(0-��1-��)
	API_DTO_FIELD_DEFAULT(UInt32, sporadicPhysical, ZH_WORDS_GETTER("getUserName.field.sporadicPhysical"));
};

/*
* ��λ�б��ҳ�������ݶ���ʵ��
*/
class UnitListPageDTO : public PageDTO<UnitListDTO::Wrapper> {
	DTO_INIT(UnitListPageDTO, PageDTO<UnitListDTO::Wrapper>);
	/*
	//����
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("getUserName.field.personName"));
	//�Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("getUserName.field.sex"));
	// ����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("getUserName.field.age"));
	//������� physicalType
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("getUserName.field.physicalType"));
	//���������(0-��1-��)
	API_DTO_FIELD_DEFAULT(UInt32, sporadicPhysical, ZH_WORDS_GETTER("getUserName.field.sporadicPhysical"));
	*/
};
#include OATPP_CODEGEN_END(DTO)
#endif // 
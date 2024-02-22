#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/15 18:22:06

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
#ifndef _REFERENCEMODDTO_H_
#define _REFERENCEMODDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* ������Ŀָ����Ŀָ���ο�ֵ�޸ĺ��������ɵ�DTO
*/
class ReferenceModDTO : public oatpp::DTO
{
	DTO_INIT(ReferenceModDTO, DTO);
	//Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("base.referenceMod.id"));
	//�ʺ��Ա�
	API_DTO_FIELD_DEFAULT(String, allowSex, ZH_WORDS_GETTER("base.referenceMod.allowSex"));
	//�������ֵ
	API_DTO_FIELD_DEFAULT(UInt32, minAge, ZH_WORDS_GETTER("base.referenceMod.minAge"));
	//�������ֵ
	API_DTO_FIELD_DEFAULT(UInt32, maxAge, ZH_WORDS_GETTER("base.referenceMod.maxAge"));
	//�����ο�ֵ
	API_DTO_FIELD_DEFAULT(String, healthyValue, ZH_WORDS_GETTER("base.referenceMod.healthyValue"));
	//ְҵ�ο�ֵ
	API_DTO_FIELD_DEFAULT(String, occupationValue, ZH_WORDS_GETTER("base.referenceMod.occupationValue"));
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_REFERENCEMODDTO_H_
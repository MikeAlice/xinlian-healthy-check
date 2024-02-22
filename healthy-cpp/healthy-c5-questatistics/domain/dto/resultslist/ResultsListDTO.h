#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���ܵ���
 @Date: 2024/1/19 17:36:29

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
#ifndef _RESULTSLIST_DTO_
#define _RESULTSLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ������������
 */
class ResultsListDTO : public oatpp::DTO
{
	DTO_INIT(ResultsListDTO, DTO);
	// �����
	DTO_FIELD(String, checkId);
	DTO_FIELD_INFO(checkId) {
		info->description = ZH_WORDS_GETTER("results.field.checkId");
	}
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("results.field.name");
	}
	// ����
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("results.field.age");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("results.field.sex");
	}
	
	//���֤��
	DTO_FIELD(String, idCard);
	DTO_FIELD_INFO(idCard) {
		info->description = ZH_WORDS_GETTER("results.field.idCard");
	}

	//���״̬
	DTO_FIELD(String, checkState);
	DTO_FIELD_INFO(checkState) {
		info->description = ZH_WORDS_GETTER("results.field.checkState");
	}

	//�ڸ�״̬
	DTO_FIELD(String, dutyState);
	DTO_FIELD_INFO(dutyState) {
		info->description = ZH_WORDS_GETTER("results.field.dutyState");
	}

	//Σ������
	DTO_FIELD(String, dangerFactors);
	DTO_FIELD_INFO(dangerFactors) {
		info->description = ZH_WORDS_GETTER("results.field.dangerFactors");
	}

	//�������
	DTO_FIELD(String, checkDate);
	DTO_FIELD_INFO(checkDate) {
		info->description = ZH_WORDS_GETTER("results.field.checkDate");
	}

	//������
	DTO_FIELD(String, checkResults);
	DTO_FIELD_INFO(checkResults) {
		info->description = ZH_WORDS_GETTER("results.field.checkResults");
	}

	//δ�����Ŀ
	DTO_FIELD(String, unfinishedProject);
	DTO_FIELD_INFO(unfinishedProject) {
		info->description = ZH_WORDS_GETTER("results.field.unfinishedProject");
	}

};

/**
 * ��ȡ�������ҳ�������
 */
class ResultsListPageDTO : public PageDTO<ResultsListDTO::Wrapper>
{
	DTO_INIT(ResultsListPageDTO, PageDTO<ResultsListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RESULTSLIST_DTO_
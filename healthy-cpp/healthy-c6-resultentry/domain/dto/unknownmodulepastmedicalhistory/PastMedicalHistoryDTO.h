#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

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
#ifndef _PASTMEDICALHISTORYCONTRONLLER_DTO_
#define _PASTMEDICALHISTORYCONTRONLLER_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ���޸��û���Ϣ�����ݴ���ģ��
 */
class PastMedicalHistoryDTO : public oatpp::DTO
{
	DTO_INIT(PastMedicalHistoryDTO, DTO);
	// Ψһ���
	API_DTO_FIELD_DEFAULT(String, person_id, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.person_id"));
	// ����
	API_DTO_FIELD_DEFAULT(UInt32, abortion, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.abortion"));
	// ���
	API_DTO_FIELD_DEFAULT(UInt32, premature, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.premature"));
	// ����
	API_DTO_FIELD_DEFAULT(UInt32, death, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.death"));
	// �쳣̥
	API_DTO_FIELD_DEFAULT(UInt32, abnormal_fetus, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.abnormal_fetus"));
	// �¾�ʷ
	API_DTO_FIELD_DEFAULT(String, menstrual_history, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.menstrual_history"));
	// �¾��쳣��Ϣ
	API_DTO_FIELD_DEFAULT(String, menstrual_info, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.menstrual_info"));
	// ����ʷ
	API_DTO_FIELD_DEFAULT(String, allergies, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.allergies"));
	// �����쳣��Ϣ
	API_DTO_FIELD_DEFAULT(String, allergies_info, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.allergies_info"));
	// ������ʷ
	API_DTO_FIELD_DEFAULT(String, past_medical_history, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.past_medical_history"));
	// ������ʷ������Ϣ
	API_DTO_FIELD_DEFAULT(String, past_medical_history_other_info, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.past_medical_history_other_info"));
};

class PastMedicalHistoryPageDTO : public PageDTO<PastMedicalHistoryDTO::Wrapper>
{
	DTO_INIT(PastMedicalHistoryPageDTO, PageDTO<PastMedicalHistoryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_
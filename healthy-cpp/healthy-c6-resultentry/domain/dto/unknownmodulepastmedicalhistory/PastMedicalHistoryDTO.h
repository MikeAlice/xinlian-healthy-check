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
 * 定义一个修改用户信息的数据传输模型
 */
class PastMedicalHistoryDTO : public oatpp::DTO
{
	DTO_INIT(PastMedicalHistoryDTO, DTO);
	// 唯一编号
	API_DTO_FIELD_DEFAULT(String, person_id, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.person_id"));
	// 流产
	API_DTO_FIELD_DEFAULT(UInt32, abortion, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.abortion"));
	// 早产
	API_DTO_FIELD_DEFAULT(UInt32, premature, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.premature"));
	// 死亡
	API_DTO_FIELD_DEFAULT(UInt32, death, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.death"));
	// 异常胎
	API_DTO_FIELD_DEFAULT(UInt32, abnormal_fetus, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.abnormal_fetus"));
	// 月经史
	API_DTO_FIELD_DEFAULT(String, menstrual_history, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.menstrual_history"));
	// 月经异常信息
	API_DTO_FIELD_DEFAULT(String, menstrual_info, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.menstrual_info"));
	// 过敏史
	API_DTO_FIELD_DEFAULT(String, allergies, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.allergies"));
	// 过敏异常信息
	API_DTO_FIELD_DEFAULT(String, allergies_info, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.allergies_info"));
	// 既往病史
	API_DTO_FIELD_DEFAULT(String, past_medical_history, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.past_medical_history"));
	// 既往病史其他信息
	API_DTO_FIELD_DEFAULT(String, past_medical_history_other_info, ZH_WORDS_GETTER("unknownmodulepastmedicalhistory.dto.past_medical_history_other_info"));
};

class PastMedicalHistoryPageDTO : public PageDTO<PastMedicalHistoryDTO::Wrapper>
{
	DTO_INIT(PastMedicalHistoryPageDTO, PageDTO<PastMedicalHistoryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_
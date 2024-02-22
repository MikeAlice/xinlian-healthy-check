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
#ifndef _LIFEHISTORYCONTRONLLER_DTO_
#define _LIFEHISTORYCONTRONLLER_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ���޸��û���Ϣ�����ݴ���ģ��
 */
class LifeHistoryDTO : public oatpp::DTO
{
	DTO_INIT(LifeHistoryDTO, DTO);
	// Ψһ���
	API_DTO_FIELD_DEFAULT(String, person_id, ZH_WORDS_GETTER("unknownmodulelifehistory.dto.person_id"));
	// ������Ů������ʷ��
	API_DTO_FIELD_DEFAULT(UInt32, existing_children, ZH_WORDS_GETTER("unknownmodulelifehistory.dto.existing_children"));
	// ����ʷ
	API_DTO_FIELD_DEFAULT(String, allergies, ZH_WORDS_GETTER("unknownmodulelifehistory.dto.allergies"));
	// ����״̬
	API_DTO_FIELD_DEFAULT(String, smoke_state, ZH_WORDS_GETTER("unknownmodulelifehistory.dto.smoke_state"));
	// ��ÿ��
	API_DTO_FIELD_DEFAULT(UInt32, package_every_day, ZH_WORDS_GETTER("unknownmodulelifehistory.fielddtopackage_every_day"));
	// ������
	API_DTO_FIELD_DEFAULT(UInt32, smoke_year, ZH_WORDS_GETTER("unknownmodulelifehistory.dto.smoke_year"));
	// �Ⱦ�״̬
	API_DTO_FIELD_DEFAULT(String, drink_state, ZH_WORDS_GETTER("unknownmodulelifehistory.dto.drink_state"));
	// mlÿ��
	API_DTO_FIELD_DEFAULT(UInt32, ml_every_day, ZH_WORDS_GETTER("unknownmodulelifehistory.dto.ml_every_day"));
	// �Ⱦ���
	API_DTO_FIELD_DEFAULT(UInt32, drink_year, ZH_WORDS_GETTER("unknownmodulelifehistory.dto.drink_year"));
	// ������
	API_DTO_FIELD_DEFAULT(String, birthplace_name, ZH_WORDS_GETTER("unknownmodulelifehistory.dto.birthplace_name"));
	// ����ʷ
	API_DTO_FIELD_DEFAULT(String, family_history, ZH_WORDS_GETTER("unknownmodulelifehistory.dto.family_history"));
};

class LifeHistoryPageDTO : public PageDTO<LifeHistoryDTO::Wrapper>
{
	DTO_INIT(LifeHistoryPageDTO, PageDTO<LifeHistoryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_
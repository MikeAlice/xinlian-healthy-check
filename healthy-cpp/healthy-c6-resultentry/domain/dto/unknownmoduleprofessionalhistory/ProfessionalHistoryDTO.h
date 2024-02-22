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
#ifndef _PROFESSIONALHISTORYCONTRONLLER_DTO_
#define _PROFESSIONALHISTORYCONTRONLLER_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ���޸��û���Ϣ�����ݴ���ģ��
 */
class ProfessionalHistoryDTO : public oatpp::DTO
{
	DTO_INIT(ProfessionalHistoryDTO, DTO);
	// Ψһ���
	API_DTO_FIELD_DEFAULT(String, person_id, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.person_id"));
	// ��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_date, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.start_date"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_date, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.end_date"));
	// ������λ
	API_DTO_FIELD_DEFAULT(String, work_unit, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.work_unit"));
	// ���䣨���ţ�
	API_DTO_FIELD_DEFAULT(String, department, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.department"));
	// ����
	API_DTO_FIELD_DEFAULT(String, work_type_text, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.work_type_text"));
	// Σ������
	API_DTO_FIELD_DEFAULT(String, hazard_factors_text, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.hazard_factors_text"));
	// ������ʩ
	API_DTO_FIELD_DEFAULT(String, protective_measures, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.protective_measures"));
	// �Ӵ�ʱ��
	API_DTO_FIELD_DEFAULT(String, contact_time, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.contact_time"));
};

class ProfessionalHistoryPageDTO : public PageDTO<ProfessionalHistoryDTO::Wrapper>
{
	DTO_INIT(ProfessionalHistoryPageDTO, PageDTO<ProfessionalHistoryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_
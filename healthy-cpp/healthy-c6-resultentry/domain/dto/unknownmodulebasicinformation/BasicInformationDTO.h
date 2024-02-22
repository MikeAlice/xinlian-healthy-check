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
#ifndef _BASICINFORMATIONCONTROLLER_DTO_
#define _BASICINFORMATIONCONTROLLER_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ���޸��û���Ϣ�����ݴ���ģ��
 */
class BasicInformationDTO : public oatpp::DTO
{
	DTO_INIT(BasicInformationDTO, DTO);
	// Ψһ���
	API_DTO_FIELD_DEFAULT(String, person_id, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.person_id"));
	// ���⹤������
	API_DTO_FIELD_DEFAULT(String, job, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.job"));
	// ��������
	API_DTO_FIELD_DEFAULT(UInt32, work_year, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.work_year"));
	// ��������
	API_DTO_FIELD_DEFAULT(UInt32, work_month, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.work_month"));
	// �Ӻ���ʼʱ��
	API_DTO_FIELD_DEFAULT(String, exposure_start_date, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.exposure_start_date"));
	// �Ļ��̶�
	API_DTO_FIELD_DEFAULT(String, education, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.education"));
	// ��ͥסַ
	API_DTO_FIELD_DEFAULT(String, family_address, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.family_address"));
	// ����״��
	API_DTO_FIELD_DEFAULT(String, marriage_date, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.marriage_date"));
};

class BasicInformationPageDTO : public PageDTO<BasicInformationDTO::Wrapper>
{
	DTO_INIT(BasicInformationPageDTO, PageDTO<BasicInformationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_
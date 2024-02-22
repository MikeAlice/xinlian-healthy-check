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
 * 定义一个修改用户信息的数据传输模型
 */
class BasicInformationDTO : public oatpp::DTO
{
	DTO_INIT(BasicInformationDTO, DTO);
	// 唯一编号
	API_DTO_FIELD_DEFAULT(String, person_id, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.person_id"));
	// 特殊工种名称
	API_DTO_FIELD_DEFAULT(String, job, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.job"));
	// 工龄年数
	API_DTO_FIELD_DEFAULT(UInt32, work_year, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.work_year"));
	// 工龄月数
	API_DTO_FIELD_DEFAULT(UInt32, work_month, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.work_month"));
	// 接害开始时间
	API_DTO_FIELD_DEFAULT(String, exposure_start_date, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.exposure_start_date"));
	// 文化程度
	API_DTO_FIELD_DEFAULT(String, education, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.education"));
	// 家庭住址
	API_DTO_FIELD_DEFAULT(String, family_address, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.family_address"));
	// 婚姻状况
	API_DTO_FIELD_DEFAULT(String, marriage_date, ZH_WORDS_GETTER("unknownmodulebasicinformation.dto.marriage_date"));
};

class BasicInformationPageDTO : public PageDTO<BasicInformationDTO::Wrapper>
{
	DTO_INIT(BasicInformationPageDTO, PageDTO<BasicInformationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: DY
 @Date: 2022/01/16 11:01:02

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
#ifndef _INFO_LIST_DTO_H_
#define _INFO_LIST_DTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表传输数据对象实体
 */
class InfoListDTO : public oatpp::DTO
{
	// 定义初始化
	DTO_INIT(InfoListDTO, DTO);

	API_DTO_FIELD_DEFAULT(UInt32, id, ZH_WORDS_GETTER("Info.field.id"));

	//体检人员
	API_DTO_FIELD_DEFAULT(UInt32, personId, ZH_WORDS_GETTER("Info.field.personId"));

	//总检医生
	API_DTO_FIELD_DEFAULT(String, inspectionDoctor, ZH_WORDS_GETTER("Info.field.inspectionDoctor"));

	//总检日期
	API_DTO_FIELD_DEFAULT(String, inspectionDate, ZH_WORDS_GETTER("Info.field.inspectionDate"));

	//医学建议
	API_DTO_FIELD_DEFAULT(String, medicalAdvice, ZH_WORDS_GETTER("Info.field.medicalAdvice"));

	//处理意见
	API_DTO_FIELD_DEFAULT(String, handleOpinion, ZH_WORDS_GETTER("Info.field.handleOpinion"));

};

/**
 * 单位列表分页数据实体
 */

class InfoListPageDTO : public PageDTO<InfoListDTO::Wrapper> {
	// 定义初始化
	DTO_INIT(InfoListPageDTO, PageDTO<InfoListDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_

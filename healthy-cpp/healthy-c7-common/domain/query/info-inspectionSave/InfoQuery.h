#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: DY
 @Date: 2024/01/19 11:36:29

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
#ifndef _INFO_QUERY_
#define _INFO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class InfoQuery : public PageQuery
{
	DTO_INIT(InfoQuery, PageQuery);
	
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

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
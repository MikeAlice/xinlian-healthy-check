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
#ifndef _REPORT_DTO_H_
#define _REPORT_DTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表传输数据对象实体
 */
class ReportDTO : public oatpp::DTO
{
	DTO_INIT(ReportDTO, DTO);
	
	// PDF地址
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("report.field.href"));
	

};


#include OATPP_CODEGEN_END(DTO)
#endif // !_REPORT_DTO_H_

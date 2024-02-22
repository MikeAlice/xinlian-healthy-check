/*
 Copyright Zero One Star. All rights reserved.

 @Author: กฃบร
 @Date: 2024/01/14 21:36:24

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
#ifndef _MEDEXAMUNITORDERQUERY_H_
#define _MEDEXAMUNITORDERQUERY_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class MedExamUnitOrderQuery : public PageQuery
{
	DTO_INIT(MedExamUnitOrderQuery, PageQuery)
	DTO_FIELD(String, unitName);
	DTO_FIELD_INFO(unitName) {
		info->description = ZH_WORDS_GETTER("MedExamUnitOrder.field.unit-name");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MEDEXAMUNITORDERQUERY_H_
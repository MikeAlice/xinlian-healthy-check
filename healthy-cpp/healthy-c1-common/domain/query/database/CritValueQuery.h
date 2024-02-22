#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: stoner
 @Date: 2024/01/14
 @FileName: CritValueQuery
 @version: 1.0

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
#ifndef _CRITVALUEQUERY_
#define _CRITVALUEQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * ��ȡָ����Ŀָ��Σ��ֵ����
 */
class CritValueQuery : public oatpp::DTO
{
	DTO_INIT(CritValueQuery, DTO);
	// id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("criticalValue.field.id"));
	// base_project_id ��Ŀid
	API_DTO_FIELD_DEFAULT(String, baseProjectId, ZH_WORDS_GETTER("criticalValue.field.baseProjectId"));
	//level �ȼ�
	API_DTO_FIELD_DEFAULT(String, level, ZH_WORDS_GETTER("criticalValue.field.level"));
	//type ����
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("criticalValue.field.type"));
	//interval_value ����ֵ
	API_DTO_FIELD_DEFAULT(String, intervalValue, ZH_WORDS_GETTER("criticalValue.field.intervalValue"));
	// allow_sex �ʺ��Ա�
	API_DTO_FIELD_DEFAULT(String, allowSex, ZH_WORDS_GETTER("criticalValue.field.allowSex"));
	// min_age �������ֵ
	API_DTO_FIELD_DEFAULT(Int64, minAge, ZH_WORDS_GETTER("criticalValue.field.minAge"));
	// max_age �������ֵ
	API_DTO_FIELD_DEFAULT(Int64, maxAge, ZH_WORDS_GETTER("criticalValue.field.maxAge"));
	// department_id ��������
	API_DTO_FIELD_DEFAULT(String, departmentId, ZH_WORDS_GETTER("criticalValue.filed.departmentId"));
	// create_id ������
	API_DTO_FIELD_DEFAULT(String, createId, ZH_WORDS_GETTER("criticalValue.field.createId"));
	// create_time ����ʱ��
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("criticalValue.field.createTime"));

};

#include OATPP_CODEGEN_END(DTO)
#endif
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: firmiana
 @Date: 2024/01/23
 @FileName: SelectBaseProjectQuery.h
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
#include "domain/query/PageQuery.h"
#ifndef _SELECT_BASEPROJECTQUERY_H_
#define _SELECT_BASEPROJECTQUERY_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SelectBaseProjectQuery : public PageQuery
{
	DTO_INIT(SelectBaseProjectQuery, PageQuery);
	// id 主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("common.baseproject.field.id"));
	// code 项目代码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("common.baseproject.field.code"));
	// name 名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("common.baseproject.field.name"));
	// short_name 简称
	API_DTO_FIELD_DEFAULT(String, short_name, ZH_WORDS_GETTER("common.baseproject.field.short_name"));
	// order_num 排序
	API_DTO_FIELD_DEFAULT(Float32, order_num, ZH_WORDS_GETTER("common.baseproject.field.order_num"));
	// office_id 科室id
	API_DTO_FIELD_DEFAULT(String, office_id, ZH_WORDS_GETTER("common.baseproject.field.office_id"));
	// office_name 科室名称
	API_DTO_FIELD_DEFAULT(String, office_name, ZH_WORDS_GETTER("common.baseproject.field.office_name"));
	// unit_code 单位编码
	API_DTO_FIELD_DEFAULT(String, unit_code, ZH_WORDS_GETTER("common.baseproject.field.unit_code"));
	// unit_name 单位名称
	API_DTO_FIELD_DEFAULT(String, unit_name, ZH_WORDS_GETTER("common.baseproject.field.unit_name"));
	// default_value 默认值
	API_DTO_FIELD_DEFAULT(String, default_value, ZH_WORDS_GETTER("common.baseproject.field.default_value"));
	// result_type 结果类型
	API_DTO_FIELD_DEFAULT(String, result_type, ZH_WORDS_GETTER("common.baseproject.field.result_type"));
	// in_conclusion 是否进入小结
	API_DTO_FIELD_DEFAULT(String, in_conclusion, ZH_WORDS_GETTER("common.baseproject.field.in_conclusion"));
	// in_report 是否进入报告
	API_DTO_FIELD_DEFAULT(String, in_report, ZH_WORDS_GETTER("common.baseproject.field.in_report"));
	// relation_code LIS关联码
	API_DTO_FIELD_DEFAULT(String, relation_code, ZH_WORDS_GETTER("common.baseproject.field.relation_code"));
	// del_flag 是否删除(0-未删除，1-已删除)
	API_DTO_FIELD_DEFAULT(UInt32, del_flag, ZH_WORDS_GETTER("common.baseproject.field.del_flag"));
	// create_id 创建人
	API_DTO_FIELD_DEFAULT(String, create_id, ZH_WORDS_GETTER("common.baseproject.field.create_id"));
	// create_time 创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("common.baseproject.field.create_time"));
	// update_id 修改人
	API_DTO_FIELD_DEFAULT(String, update_id, ZH_WORDS_GETTER("common.baseproject.field.update_id"));
	// update_time 修改时间
	API_DTO_FIELD_DEFAULT(String, update_time, ZH_WORDS_GETTER("common.baseproject.field.update_time"));
	// delete_id 删除人
	API_DTO_FIELD_DEFAULT(String, delete_id, ZH_WORDS_GETTER("common.baseproject.field.delete_id"));
	// delete_time 删除时间
	API_DTO_FIELD_DEFAULT(String, delete_time, ZH_WORDS_GETTER("common.baseproject.field.delete_time"));
	// department_id 所属部门
	API_DTO_FIELD_DEFAULT(String, department_id, ZH_WORDS_GETTER("common.baseproject.field.department_id"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SELECT_BASEPROJECTQUERY_H_
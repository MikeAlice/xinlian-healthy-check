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
	// id ����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("common.baseproject.field.id"));
	// code ��Ŀ����
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("common.baseproject.field.code"));
	// name ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("common.baseproject.field.name"));
	// short_name ���
	API_DTO_FIELD_DEFAULT(String, short_name, ZH_WORDS_GETTER("common.baseproject.field.short_name"));
	// order_num ����
	API_DTO_FIELD_DEFAULT(Float32, order_num, ZH_WORDS_GETTER("common.baseproject.field.order_num"));
	// office_id ����id
	API_DTO_FIELD_DEFAULT(String, office_id, ZH_WORDS_GETTER("common.baseproject.field.office_id"));
	// office_name ��������
	API_DTO_FIELD_DEFAULT(String, office_name, ZH_WORDS_GETTER("common.baseproject.field.office_name"));
	// unit_code ��λ����
	API_DTO_FIELD_DEFAULT(String, unit_code, ZH_WORDS_GETTER("common.baseproject.field.unit_code"));
	// unit_name ��λ����
	API_DTO_FIELD_DEFAULT(String, unit_name, ZH_WORDS_GETTER("common.baseproject.field.unit_name"));
	// default_value Ĭ��ֵ
	API_DTO_FIELD_DEFAULT(String, default_value, ZH_WORDS_GETTER("common.baseproject.field.default_value"));
	// result_type �������
	API_DTO_FIELD_DEFAULT(String, result_type, ZH_WORDS_GETTER("common.baseproject.field.result_type"));
	// in_conclusion �Ƿ����С��
	API_DTO_FIELD_DEFAULT(String, in_conclusion, ZH_WORDS_GETTER("common.baseproject.field.in_conclusion"));
	// in_report �Ƿ���뱨��
	API_DTO_FIELD_DEFAULT(String, in_report, ZH_WORDS_GETTER("common.baseproject.field.in_report"));
	// relation_code LIS������
	API_DTO_FIELD_DEFAULT(String, relation_code, ZH_WORDS_GETTER("common.baseproject.field.relation_code"));
	// del_flag �Ƿ�ɾ��(0-δɾ����1-��ɾ��)
	API_DTO_FIELD_DEFAULT(UInt32, del_flag, ZH_WORDS_GETTER("common.baseproject.field.del_flag"));
	// create_id ������
	API_DTO_FIELD_DEFAULT(String, create_id, ZH_WORDS_GETTER("common.baseproject.field.create_id"));
	// create_time ����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("common.baseproject.field.create_time"));
	// update_id �޸���
	API_DTO_FIELD_DEFAULT(String, update_id, ZH_WORDS_GETTER("common.baseproject.field.update_id"));
	// update_time �޸�ʱ��
	API_DTO_FIELD_DEFAULT(String, update_time, ZH_WORDS_GETTER("common.baseproject.field.update_time"));
	// delete_id ɾ����
	API_DTO_FIELD_DEFAULT(String, delete_id, ZH_WORDS_GETTER("common.baseproject.field.delete_id"));
	// delete_time ɾ��ʱ��
	API_DTO_FIELD_DEFAULT(String, delete_time, ZH_WORDS_GETTER("common.baseproject.field.delete_time"));
	// department_id ��������
	API_DTO_FIELD_DEFAULT(String, department_id, ZH_WORDS_GETTER("common.baseproject.field.department_id"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SELECT_BASEPROJECTQUERY_H_
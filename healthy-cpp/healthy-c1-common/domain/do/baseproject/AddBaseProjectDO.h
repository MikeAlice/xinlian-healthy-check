#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: firmiana
 @Date: 2024/01/23
 @FileName: AddBaseProjectDO.h
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
#ifndef _ADDBASEPROJECT_DO_H_
#define _ADDBASEPROJECT_DO_H_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class AddBaseProjectDO
{
	// id ����
	//CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, id, Id);
	// code ��Ŀ����
	CC_SYNTHESIZE(string, code, Code);
	// name ����
	CC_SYNTHESIZE(string, name, Name);
	// short_name ���
	CC_SYNTHESIZE(string, short_name, ShortName);
	// order_num ����
	CC_SYNTHESIZE(float, order_num, OrderNum);
	// office_id ����id
	CC_SYNTHESIZE(string, office_id, OfficeId);
	// office_name ��������
	CC_SYNTHESIZE(string, office_name, OfficeName);
	// unit_code ��λ����
	CC_SYNTHESIZE(string, unit_code, UnitCode);
	// unit_name ��λ����
	CC_SYNTHESIZE(string, unit_name, UnitName);
	// default_value Ĭ��ֵ
	CC_SYNTHESIZE(string, default_value, DefaultValue);
	// result_type �������
	CC_SYNTHESIZE(string, result_type, ResultType);
	// in_conclusion �Ƿ����С��
	CC_SYNTHESIZE(string, in_conclusion, InConclusion);
	// in_report �Ƿ���뱨��
	CC_SYNTHESIZE(string, in_report, InReport);
	// relation_code LIS������
	CC_SYNTHESIZE(string, relation_code, RelationCode);
	// del_flag �Ƿ�ɾ��(0-δɾ����1-��ɾ��)
	CC_SYNTHESIZE(unsigned int, del_flag, DelFlag);
	// create_id ������
	CC_SYNTHESIZE(string, create_id, CreateId);
	// create_time ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// update_id �޸���
	CC_SYNTHESIZE(string, update_id, UpdateId);
	// update_time �޸�ʱ��
	CC_SYNTHESIZE(string, update_time, UpdateTime);
	// delete_id ɾ����
	CC_SYNTHESIZE(string, delete_id, DeleteId);
	// delete_time ɾ��ʱ��
	CC_SYNTHESIZE(string, delete_time, DeleteTime);
	// department_id ��������
	CC_SYNTHESIZE(string, department_id, DepartmentId);

public:
	AddBaseProjectDO() {
		id = "";
		code = "";
		name = "";
		short_name = "";
		office_id = "";
		office_name = "";
		unit_code = "";
		unit_name = "";
		default_value = "";
		result_type = "";
		in_conclusion = "";
		in_report = "";
		relation_code = "";
		create_id = "";
		create_time = "";
		update_id = "";
		update_time = "";
		delete_id = "";
		delete_time = "";
		department_id = "";

		order_num = 1;
		del_flag = 0;
	}

};

#endif // !_ADDBASEPROJECT_DO_H_

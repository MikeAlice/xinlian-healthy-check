#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _SAMPLE_DO_
#define _SAMPLE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class DeleteSampleDO
{
	//�Ƿ�ɾ��(0-δɾ����1-��ɾ��)del_flag
	CC_SYNTHESIZE(int, del_flag, Del_flag);
	// ������create_id
	CC_SYNTHESIZE(string, create_id, Create_id);
	// ����ʱ��create_time
	CC_SYNTHESIZE(string, create_time, Create_time);
	// �޸���update_id
	CC_SYNTHESIZE(string, update_id, Update_id);
	// �޸�ʱ��update_time
	CC_SYNTHESIZE(string, update_time, Update_time);
	// ɾ����delete_id
	CC_SYNTHESIZE(string, delete_id, Delete_id);
	// ɾ��ʱ��delete_time
	CC_SYNTHESIZE(string, delete_time, Delete_time);
	// ��������department_id
	CC_SYNTHESIZE(string, department_id, Department_id);
public:
	DeleteSampleDO() {
		del_flag = 0;
		create_id = "";
		create_time = "";
		update_id = "";
		update_time = "";
		delete_id = "";
		delete_time = "";
		department_id = "";

	}
};

#endif // !_SAMPLE_DO_

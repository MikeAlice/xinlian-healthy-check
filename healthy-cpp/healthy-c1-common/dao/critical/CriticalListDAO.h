#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _CRITICAL_LIST_DAO_
#define _CRITICAL_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/critical/CriticalListDO.h"
#include "../../domain/query/critical/CriticalQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class CriticalListDAO : public BaseDAO
{
public:
	//// ͳ����������
	//uint64_t count(const SampleQuery::Wrapper& query);
	//// ��ҳ��ѯ����
	//list<SampleDO> selectWithPage(const SampleQuery::Wrapper& query);
	//// ͨ��������ѯ����
	//list<SampleDO> selectByName(const string& name);
	//// ��������
	//uint64_t insert(const SampleDO& iObj);
	//// �޸�����
	int update(const CriticalListDO& uObj);
	// ͨ��IDɾ������
	int deleteById(const CriticalListDO& uObj);
};
#endif // !_SAMPLE_DAO_

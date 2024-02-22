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
#ifndef _STATISTICALMESSAGEQUERY_DAO_
#define _STATISTICALMESSAGEQUERY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/statisticalmessage/StatisticalMessageDO.h"
#include "../../domain/query/statisticalmessage/StatisticalMessageQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class StatisticalMessageDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const StatisticalMessageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<StatisticalMessageDO> selectWithPage(const StatisticalMessageQuery::Wrapper& query);
	//uint64_t countFinished(const StatisticalMessageQuery::Wrapper& query);
	// ͨ��������ѯ����
	//list<JoinPersonListDO> selectByName(const string& name);
	// ��������
	//uint64_t insert(const JoinPersonListDO& iObj);
	// �޸�����
	//int update(const JoinPersonListDO& uObj);
	// ͨ��IDɾ������
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_

#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: smartPiggy
 @Date: 2024-01-27

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
#ifndef _RESULTDAO_H_
#define _RESULTDAO_H_
#include "BaseDAO.h"
#include"../../domain/do/result/ResultDO.h"
#include"../../domain/query/result/ResultQuery.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class ResultDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ResultQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ResultDO> selectWithPage(const ResultQuery::Wrapper& query);
	// ͨ�������������ѯ����
	list<ResultDO> selectByPersonId(const ResultQuery::Wrapper& query, const string& PersonId);
};
#endif // !_RESULTDAO_H_

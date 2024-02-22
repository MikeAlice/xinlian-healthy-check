#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: DY
 @Date: 2022/10/25 11:08:56

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
#ifndef _INFO_LIST_SERVICE_
#define _INFO_LIST_SERVICE_
#include <list>
#include "domain/vo/info-inspectionSave/InfoVO.h"
#include "domain/query/info-inspectionSave/InfoQuery.h"
#include "domain/dto/info-inspectionSave/InfoListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class InfoListService
{
public:
	// ��ҳ��ѯ��������
	InfoListPageDTO::Wrapper listAll(const InfoQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const InfoListDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const InfoListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_


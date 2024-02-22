/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "stdafx.h"
#include "ObtainSampleDetailsService.h"
#include "../../dao/sample/ObtainSampleDetailsDAO.h"

// ��ҳ��ѯ��������
ObtainSampleDetailsPageDTO::Wrapper ObtainSampleDetailsService::listAll(const ObtainSampleDetailsQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ObtainSampleDetailsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ObtainSampleDetailsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ObtainSampleDetailsDO> result = dao.selectWithPage(query);

	// ��DOת����DTO
	for (ObtainSampleDetailsDO sub : result)
	{
		auto dto = ObtainSampleDetailsDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		dto->name = sub.getName();
		dto->barcode_num = sub.getBarcode_num();
		dto->spec = sub.getSpec(); 
		dto->need_take_blood = sub.getNeed_take_blood();
		dto->code = sub.getCode();
		dto->order_num = sub.getOrder_num(); 
		dto->is_print = sub.getIs_print(); 
		dto->liscode = sub.getLiscode();
		dto->capacity = sub.getCapacity();
		pages->addData(dto);

	}
	return pages;
}




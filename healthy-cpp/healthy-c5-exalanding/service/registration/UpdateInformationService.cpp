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
#include <list>
#include "UpdateInformationService.h"
#include "../../dao/registration/UpdateInformationDAO.h"
#include "../../domain/do/registration/UpdateInformationDO.h"

UpdateInformationDTO::Wrapper UpdateInformationService::getData(const UpdateInformationDTO::Wrapper& dto)
{
	// 构建返回对象
	auto returnDto = UpdateInformationDTO::createShared();

	// 查询数据,得到do
	UpdateInformationDAO dao;
	list<UpdateInformationDO> results = dao.selectByIdCard(dto->idCard.getValue(""));
	UpdateInformationDO dataDo = results.front();

	// 将DO转换成DTO
	ZO_STAR_DOMAIN_DO_TO_DTO(returnDto, dataDo, personName, PersonName, sex, Sex, \
		age, Age, isMarry, IsMarry, idCard, IdCard, birth, Birth, groupId, GroupId, \
		workName, WorkName, mobile, Mobile)

		return returnDto;
}

bool UpdateInformationService::updateData(const UpdateInformationDTO::Wrapper& dto)
{
	// 组装DO数据
	UpdateInformationDO dataDo;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(dataDo, dto, PersonName, personName, Sex, sex, \
		Age, age, IsMarry, isMarry, IdCard, idCard, Birth, birth, GroupId, groupId, \
		WorkName, workName, Mobile, mobile)
		// 执行数据修改
		UpdateInformationDAO dao;
	return dao.update(dataDo) == 1;
}

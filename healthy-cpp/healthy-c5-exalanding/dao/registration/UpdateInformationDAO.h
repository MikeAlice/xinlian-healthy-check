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
#ifndef _UPDATEINFORMATIONDAO_H_
#define _UPDATEINFORMATIONDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/registration/UpdateInformationDO.h"
#include "../../domain/dto/registration/UpdateInformationDTO.h"

/**
 * 示例表数据库操作实现
 */
class UpdateInformationDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const UpdateInformationDTO::Wrapper& query);
	// 通过姓名查询数据
	list<UpdateInformationDO> selectByIdCard(const string& idCard);
	// 修改数据
	int update(const UpdateInformationDO& uObj);
};
#endif // !_UPDATEINFORMATIONDAO_H_

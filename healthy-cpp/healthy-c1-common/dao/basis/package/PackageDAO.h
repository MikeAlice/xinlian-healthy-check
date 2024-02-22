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

#ifndef _PACKAGE_DAO_
#define _PACKAGE_DAO_
#include "BaseDAO.h"
#include "domain/do/basis/PackageDO.h"
#include "domain/query/basis/PackageQuery.h"

/**
 * 获取套餐名称列表数据库操作实现
 */
class PackageDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const PackageQuery::Wrapper& query);
	// 分页查询数据
	list<PackageDO> selectWithPage(const PackageQuery::Wrapper& query);
	// 通过名称查询数据
	list<PackageDO> selectByName(const string& name);
	// 通过类型查询数据
	list<PackageDO> selectByType(const string& type);
};
#endif // !_PACKAGE_DAO_

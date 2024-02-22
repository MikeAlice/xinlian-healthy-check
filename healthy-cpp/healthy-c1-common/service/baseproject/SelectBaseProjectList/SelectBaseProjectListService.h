#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: firmiana
 @Date: 2024/01/23
 @FileName: SelectBaseProjectListService.h
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
#ifndef _SELECTBASEPROJECTLIST_SERVICE_H_
#define _SELECTBASEPROJECTLIST_SERVICE_H_
#include "domain/vo/baseproject/SelectBaseProjectListVO.h"
#include "domain/query/baseproject/SelectBaseProjectListQuery.h"
#include "domain/dto/baseproject/SelectBaseProjectListDTO.h"

 /**
  * 示例服务实现，演示基础的示例服务实现
  */
class SelectBaseProjectListService
{
public:
	// 分页查询所有数据
	SelectBaseProjectListPageDTO::Wrapper listAll(const SelectBaseProjectListQuery::Wrapper& query);
};

#endif // !_SELECTBASEPROJECTLIST_SERVICE_H_


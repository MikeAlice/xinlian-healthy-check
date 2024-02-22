#pragma once
/*
 Copyright Zero One Star. All rights reserved.

<<<<<<<< HEAD:healthy-cpp/healthy-c1-common/domain/do/base/ReferenceDelDO.h
 @Author: awei
 @Date: 2022/10/25 11:52:32
========
 @Author: 。好
 @Date: 2024/01/14 19:11:39
>>>>>>>> remotes/origin/c4:healthy-cpp/healthy-c4-unitreport/controller/UnitReport/UnitReportController.cpp

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
<<<<<<<< HEAD:healthy-cpp/healthy-c1-common/domain/do/base/ReferenceDelDO.h
#ifndef _REFERENCEDELDO_H_
#define _REFERENCEDELDO_H_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ReferenceDelDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	
public:
	ReferenceDelDO() {
		id = "";
	}
};

#endif // !_REFERENCEDELDO_H_
========

#include "stdafx.h"
#include "UnitReportController.h"
#include "../../service/UnitReport/UnitReportService.h"

UnitReportJsonVO::Wrapper UnitReportController::execQueryUnitReport()
{
	UnitReportService service;
	auto result = service.listAll();
	auto jvo = UnitReportJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
>>>>>>>> remotes/origin/c4:healthy-cpp/healthy-c4-unitreport/controller/UnitReport/UnitReportController.cpp

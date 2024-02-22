/*
 Copyright Zero One Star. All rights reserved.

 @Author: smartPiggy
 @Date: 2024-01-19

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
#include"stdafx.h"
#include"./ResultController.h"
#include"../../service/result/ResultService.h"

ResultPageJsonVO::Wrapper ResultController::execQueryPrimCheck(const ResultQuery::Wrapper& query)
{
	// 定义一个Service
	ResultService service;
	// 查询数据
	auto result = service.listByPersonId(query);
	// 响应结果
	auto jvo = ResultPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

//ItemResultPageJsonVO::Wrapper ResultController::execQueryPrimCheckDetail(const ResultQuery::Wrapper& query)
//{
//	return ItemResultPageJsonVO::Wrapper();
//}

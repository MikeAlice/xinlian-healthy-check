/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2024/01/17

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
#include "ItemResultController.h"
#include "../../service/itemResult/ItemResultService.h"
#include "../ApiDeclarativeServicesHelper.h"

ItemResultPageJsonVO::Wrapper ItemResultController::execQueryItemResult(const ItemResultQuery::Wrapper& pq, const PayloadDTO& payload)
{
	////ItemResultDTO::Wrapper dto = ItemResultDTO::createShared(ZH_WORDS_GETTER("itemResult.field.name"),
	////	ZH_WORDS_GETTER("itemResult.field.defaultValue"),
	////	ZH_WORDS_GETTER("itemResult.field.unitName"),
	////	ZH_WORDS_GETTER("itemResult.field.scope"));
	//ItemResultPageJsonVO::Wrapper vo = ItemResultPageJsonVO::createShared();
	////vo->success(dto);
	//return vo;
	// 定义一个Service
	ItemResultService service;
	// 查询数据
	auto result = service.getItemResultData(pq);
	// 响应结果
	auto jvo = ItemResultPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

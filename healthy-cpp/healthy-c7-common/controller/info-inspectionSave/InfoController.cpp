/*
 Copyright Zero One Star. All rights reserved.

 @Author: DY
 @Date: 2022/01/16 10:58:42

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
#include "InfoController.h"
#include "../../service/info-inspectionSave/InfoListService.h"
#include "../ApiDeclarativeServicesHelper.h"



InfoListPageJsonVO::Wrapper InfoController::execQueryInfo(const InfoQuery::Wrapper& query)
{
	// 定义一个Service
	InfoListService service;

	InfoListDTO::Wrapper dto = InfoListDTO::createShared();

	dto->id = query->id;
 	dto->personId = query->personId;
 	dto->inspectionDoctor = query->inspectionDoctor;
 	dto->inspectionDate = query->inspectionDate;
 	dto->medicalAdvice = query->medicalAdvice;
	dto->handleOpinion = query->handleOpinion;

	service.saveData(dto);

	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = InfoListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}



/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#include "ModifyInformationController.h"
#include "../../service/registration/UpdateInformationService.h"
#include "../../domain/vo/registration/UpdateInformationJsonVO.h"
#include "../ApiDeclarativeServicesHelper.h"

UpdateInformationJsonVO::Wrapper ModifyInformationController::execModifyInformation(const UpdateInformationDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = UpdateInformationJsonVO::createShared();
	// 定义一个Service
	UpdateInformationService service;
	// 执行数据修改
	auto result = service.updateData(dto);
	if (result) {
		jvo->success(dto);
	}
	else
	{
		jvo->fail(dto);
	}

	// 响应结果
	return jvo;
}

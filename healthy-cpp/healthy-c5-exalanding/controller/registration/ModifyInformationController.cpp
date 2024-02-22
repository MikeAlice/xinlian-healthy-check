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
	// ���巵�����ݶ���
	auto jvo = UpdateInformationJsonVO::createShared();
	// ����һ��Service
	UpdateInformationService service;
	// ִ�������޸�
	auto result = service.updateData(dto);
	if (result) {
		jvo->success(dto);
	}
	else
	{
		jvo->fail(dto);
	}

	// ��Ӧ���
	return jvo;
}

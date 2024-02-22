/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "ObtainSampleDetailsController.h"
#include "../../service/sample/ObtainSampleDetailsService.h"
#include "../ApiDeclarativeServicesHelper.h"

ObtainSampleDetailsPageJsonVO::Wrapper ObtainSampleDetailsController::execQuerySampleDetails(const ObtainSampleDetailsQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ObtainSampleDetailsService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ObtainSampleDetailsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


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
#include "ReportController.h"
#include <iostream>
// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "service/ReportView/ReportService.h"
#include "SimpleDateTimeFormat.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "uselib/pdf/InspectPDF.h"

ReportJsonVO::Wrapper ReportController::execQueryreport(const ReportQuery::Wrapper& query)
{
	
	// 定义一个Service
	ReportService service;
	// 查询数据
	auto result = service.listId(query);
	// 响应结果
	auto jvo = ReportJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

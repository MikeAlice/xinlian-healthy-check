#pragma once
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
#ifndef _UnitController_H_
#define _UnitController_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/getUserName/UnitQuery.h"
#include "domain/dto/getUserName/UnitListDTO.h"
#include "domain/vo/getUserName/UnitVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class UnitController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(UnitController);
public://定义接口
	// 3.1 定义分页查询单位列表接口描述
	ENDPOINT_INFO(queryUnit) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("getUserName.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述

		//是否通过检查
		API_DEF_ADD_QUERY_PARAMS(UInt32, "ispass", ZH_WORDS_GETTER("getUserName.field.ispass"),2,true);
		// 复查状态  复查人员在复检人员信息表中查询
		API_DEF_ADD_QUERY_PARAMS(UInt32, "isRecheck", ZH_WORDS_GETTER("getUserName.field.isRecheck"),1,true);
		//开始时间
		API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("getUserName.field.startDate"), "2020-10-12", false);
		//结束时间
		API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("getUserName.field.endDate"), "2023-10-12", false);
		//姓名
		API_DEF_ADD_QUERY_PARAMS(String, "personName", ZH_WORDS_GETTER("getUserName.field.personName"), "坤坤", false);
		//体检编号
		API_DEF_ADD_QUERY_PARAMS(String, "testNum", ZH_WORDS_GETTER("getUserName.field.testNum"), "x12345", false);
		//单位名称
		API_DEF_ADD_QUERY_PARAMS(String, "dept", ZH_WORDS_GETTER("getUserName.field.dept"), "xxx有限公司", false);

		//性别
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("getUserName.field.sex"), "男", false);
		//年龄
		API_DEF_ADD_QUERY_PARAMS(UInt32, "age", ZH_WORDS_GETTER("getUserName.field.age"), 18, false);
		//体检类型 physicalType
		API_DEF_ADD_QUERY_PARAMS(String, "physicalType", ZH_WORDS_GETTER("getUserName.field.physicalType"), "职业体检", false);
		//是否零星体检(0-否，1-是)
		API_DEF_ADD_QUERY_PARAMS(UInt32, "sporadicPhysical", ZH_WORDS_GETTER("getUserName.field.sporadicPhysical"), 1, false);
	}

	//定义分页查询单位列表接口
	ENDPOINT(API_M_GET, "/getUserName/query-unit", queryUnit, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {

		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, UnitQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryUnit(uq));
	
	};

private://定义接口执行函数
	UnitListPageJsonVO::Wrapper execQueryUnit(const UnitQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 
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
#ifndef _ADD_CONTROLLER_
#define _ADD_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/unitpeople/UnitPeopleQuery.h"
#include "domain/dto/unitpeople/UnitPeopleDTO.h"
#include "domain/vo/unitpeople/UnitPeopleVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class AddController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AddController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(addPeople) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitPeoplePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "person_name", ZH_WORDS_GETTER("unit.field.personName"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("unit.field.Sex"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "id_card", ZH_WORDS_GETTER("unit.field.idCard"), "511321XXXXXXXXXXXX", false);
		API_DEF_ADD_QUERY_PARAMS(String, "birth ", ZH_WORDS_GETTER("unit.field.Birth"), "XX.XX.XX", false);
		API_DEF_ADD_QUERY_PARAMS(String, "age ", ZH_WORDS_GETTER("unit.field.Age"), "-1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "is_marry", ZH_WORDS_GETTER("unit.field.isMarry"), "YES", false);
		API_DEF_ADD_QUERY_PARAMS(String, "mobile", ZH_WORDS_GETTER("unit.field.Mobile"), "18141341717", false);
	}

	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/add", addPeople, BODY_DTO(UnitPeopleDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddPeople(dto));
	}


private:
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddPeople(const UnitPeopleDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ADD_CONTROLLER_
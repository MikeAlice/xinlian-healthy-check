#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: stoner
 @Date: 2024/01/15

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
#ifndef _ADDCRITVALUECONTROLLER_H_
#define _ADDCRITVALUECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/dto/database/CritValueDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class AddCritValueController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(AddCritValueController);
public:
	// 定义接口
	// 定义新增接口描述
	ENDPOINT_INFO(addCriticalValue) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("criticalValue.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/database", addCriticalValue, BODY_DTO(CritValueDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execCriticalValue(dto));
	}

private:
	// 定义接口执行函数
	// 演示新增数据
	Uint64JsonVO::Wrapper execCriticalValue(const CritValueDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_
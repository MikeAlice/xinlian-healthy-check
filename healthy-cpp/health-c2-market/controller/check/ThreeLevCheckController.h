#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: luoluo
 @Date: 2024/1/21 0:27:04

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
#ifndef _THREELEVCHECK_CONTROLLER_
#define _THREELEVCHECK_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/dto/check/ThreeLevCheckDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ThreeLevCheckController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ThreeLevCheckController);
public:
	//  定义新增接口描述
	ENDPOINT_INFO(addThreeLevCheck) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("threelevcheck.post.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//  定义新增接口处理
	ENDPOINT(API_M_POST, "/threelevcheck", addThreeLevCheck, BODY_DTO(ThreeLevCheckDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddThreeLevCheck(dto));
	}

private:
	//  演示新增数据
	Uint64JsonVO::Wrapper execAddThreeLevCheck(const ThreeLevCheckDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _THREELEVCHECK_CONTROLLER_
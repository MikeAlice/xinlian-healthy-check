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
#ifndef _CLABANPROJCONTROLLER_H_
#define _CLABANPROJCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/result-entry/ClAbanProjDTO.h"
#include "domain/vo/result-entry/ClAbanProjVO.h"
#include "domain/GlobalInclude.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class ClAbanProjController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ClAbanProjController);
	// 3 定义接口
public:

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("result-entry.cl-aban-proj.put.summary"), modifyProjState, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/resultentry/cl-aban-proj", modifyProjState, BODY_DTO(ClAbanProjDTO::Wrapper, dto), execModifyProjState(dto));

private:

	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyProjState(const ClAbanProjDTO::Wrapper& dto);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
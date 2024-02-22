#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

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
#ifndef _REFERENCEMODCONTROLLER_H_
#define _REFERENCEMODCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/base/ReferenceModVO.h"
#include "../../domain/dto/base/ReferenceModDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ReferenceModController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ReferenceModController);
public://定义接口
	//定义参考值修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("base.referenceMod.put.summary"), modifyReference, Uint64JsonVO::Wrapper);
	//定义参考值修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/base/modifyReference", modifyReference, BODY_DTO(ReferenceModDTO::Wrapper, dto), execModifyReference(dto));
		
	
private://定义接口执行函数
	Uint64JsonVO::Wrapper execModifyReference(const ReferenceModDTO::Wrapper& modDto);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _REFERENCEMODCONTROLLER_H_
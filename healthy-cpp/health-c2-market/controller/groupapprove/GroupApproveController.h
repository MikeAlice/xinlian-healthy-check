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
#ifndef _GROUPAPPROVE_CONTROLLER_
#define _GROUPAPPROVE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/groupapprove/GroupApproveQuery.h"
#include "domain/dto/groupapprove/GroupApproveDTO.h"
#include "domain/vo/groupapprove/GroupApproveVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class GroupApproveController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(GroupApproveController);
	// 3 定义接口
public:
	
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addGroupApprove) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("groupapprove.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/groupapprove", addGroupApprove, BODY_DTO(GroupApproveDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddGroupApprove(dto));
	}

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("groupapprove.put.summary"), modifyGroupApprove, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/groupapprove", modifyGroupApprove, BODY_DTO(GroupApproveDTO::Wrapper, dto), execModifyGroupApprove(dto));

	
private:
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddGroupApprove(const GroupApproveDTO::Wrapper& dto);
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyGroupApprove(const GroupApproveDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _GROUPAPPROVE_CONTROLLER_
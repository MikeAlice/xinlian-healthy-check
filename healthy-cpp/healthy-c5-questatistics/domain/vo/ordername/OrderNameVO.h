#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 会跑的鱼
 @Date: 2024/1/19 17:36:29

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
#ifndef _ORDERNAME_VO_
#define _ORDERNAME_VO_

#include "../../GlobalInclude.h"
#include "../../dto/ordername/OrderNameDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 体检单位订单名称显示JsonVO，用于响应给客户端的Json对象
 */
class OrderNameJsonVO : public JsonVO<OrderNameDTO::Wrapper> {
	DTO_INIT(OrderNameJsonVO, JsonVO<OrderNameDTO::Wrapper>);
};

/**
 * 体检单位订单名称分页显示JsonVO，用于响应给客户端的Json对象
 */
class OrderNamePageJsonVO : public JsonVO<OrderNamePageDTO::Wrapper> {
	DTO_INIT(OrderNamePageJsonVO, JsonVO<OrderNamePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORDERNAME_VO_
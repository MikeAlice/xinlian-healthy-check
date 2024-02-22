#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: lenya~
 @Date: 2024/1/18

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
#ifndef _USERVO_H_
#define _USERVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/evalue/InquiryDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个问诊明细信息显示JsonVO对象
 */
class InquiryDetailJsonVO : public JsonVO<InquiryDetailDTO::Wrapper>
{
	DTO_INIT(InquiryDetailJsonVO, JsonVO<InquiryDetailDTO::Wrapper>);
};

/**
 * 定义一个问诊明细信息分页显示JsonVO对象
 */
class InquiryDetailPageJsonVO : public JsonVO<InquiryDetailPageDTO::Wrapper>
{
	DTO_INIT(InquiryDetailPageJsonVO, JsonVO<InquiryDetailPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_
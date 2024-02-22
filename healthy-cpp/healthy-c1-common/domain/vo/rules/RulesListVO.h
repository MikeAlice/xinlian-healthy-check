#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: c1-pepper
 @Date: 2024/1/15

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
#ifndef _RULESLISTVO_H_
#define _RULESLISTVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/rules/RulesListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class RulesListJsonVO : public JsonVO<RulesListDTO::Wrapper>
{
	DTO_INIT(RulesListJsonVO, JsonVO<RulesListDTO::Wrapper>);
public:
	// �ڹ��캯����ʵ����data�б�
	RulesListJsonVO() {
		this->data = {};
	}
};
/**
 * ����һ���û���Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class RulesListPageJsonVO : public JsonVO<RulesListPageDTO::Wrapper>
{
	DTO_INIT(RulesListPageJsonVO, JsonVO<RulesListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RULESLISTVO_H_
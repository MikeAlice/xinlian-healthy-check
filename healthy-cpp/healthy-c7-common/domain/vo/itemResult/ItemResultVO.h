#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���֮��
 @Date: 2024/01/17

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
#ifndef _ITEMRESULTVO_H_
#define _ITEMRESULTVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/itemResult/ItemResultDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ�����Ŀ�����ϸ��ʾJsonVOʵ��
 * �����ˣ����֮��
 */
class ItemResultJsonVO : public JsonVO<ItemResultDTO::Wrapper>
{
	DTO_INIT(ItemResultJsonVO, JsonVO<ItemResultDTO::Wrapper>);
};
/**
 * ��ȡ�����Ŀ�����ϸ��ҳ��ʾJsonVOʵ��
 * �����ˣ����֮��
 */
class ItemResultPageJsonVO : public JsonVO<ItemResultPageDTO::Wrapper>
{
	DTO_INIT(ItemResultPageJsonVO, JsonVO<ItemResultPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ITEMRESULTVO_H_
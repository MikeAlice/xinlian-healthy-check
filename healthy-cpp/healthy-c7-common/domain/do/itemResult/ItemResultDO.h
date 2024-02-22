#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���֮��
 @Date: 2024/01/28

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
#ifndef _ITEMRESULTDO_H_
#define _ITEMRESULTDO_H_
#include "../DoInclude.h"

/**
 * ��ȡ�����Ŀ�����ϸ�����ݿ�ʵ����
 */
class ItemResultDO
{
	// �����Ŀ����
	CC_SYNTHESIZE(string, name, Name);
	// ���
	CC_SYNTHESIZE(string, defaultValue, DefaultValue);
	// ��λ
	CC_SYNTHESIZE(string, unitName, UnitName);
	// �ο���Χ
	CC_SYNTHESIZE(string, scope, Scope);
public:
	ItemResultDO() {
		name = "";
		defaultValue = "";
		unitName = "";
		scope = "";
	}
};

#endif // !_ITEMRESULTDO_H_


/*
 Copyright Zero One Star. All rights reserved.

 @Author: c1-pepper
 @Date: 2024/1/14 

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
#ifndef _RULESLISTPAGEQUERY_H_
#define _RULESLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡָ����Ŀ�����б�(��ҳ)
 */
class RulesListPageQuery : public PageQuery
{
	//?pageNumber=1&pageSize=10&sort=create_time&order=desc
	// �����ʼ��
	DTO_INIT(RulesListPageQuery, PageQuery);

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RULESLIST_H_
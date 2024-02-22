#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���ܵ���
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
#ifndef _RESULTSLIST_VO_
#define _RESULTSLIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/resultslist/ResultsListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ResultsListJsonVO : public JsonVO<ResultsListDTO::Wrapper> {
	DTO_INIT(ResultsListJsonVO, JsonVO<ResultsListDTO::Wrapper>);
};

/**
 * �����۷�ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ResultsListPageJsonVO : public JsonVO<ResultsListPageDTO::Wrapper> {
	DTO_INIT(ResultsListPageJsonVO, JsonVO<ResultsListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RESULTSLIST_VO_
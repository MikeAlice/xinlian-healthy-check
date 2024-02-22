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

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ClAbanProjController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ClAbanProjController);
	// 3 ����ӿ�
public:

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("result-entry.cl-aban-proj.put.summary"), modifyProjState, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/resultentry/cl-aban-proj", modifyProjState, BODY_DTO(ClAbanProjDTO::Wrapper, dto), execModifyProjState(dto));

private:

	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyProjState(const ClAbanProjDTO::Wrapper& dto);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
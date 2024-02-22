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
#ifndef _MODIFYINFORMATIONH_CONTROLLER_
#define _MODIFYINFORMATIONH_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/registration/UpdateInformationDTO.h"
#include "../../domain/vo/registration/UpdateInformationJsonVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ModifyInformationController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ModifyInformationController);

	// 3 ����ӿ�	
public:
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("exalanding.put.modifyInformation"), modifyInformation, UpdateInformationJsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/exalanding/modify-information", modifyInformation, BODY_DTO(UpdateInformationDTO::Wrapper, dto), execModifyInformation(dto));


	// ����ӿ�ִ�к���
private:
	// 3.3 ��ʾ�޸�����
	UpdateInformationJsonVO::Wrapper execModifyInformation(const UpdateInformationDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MODIFYINFORMATIONH_CONTROLLER_
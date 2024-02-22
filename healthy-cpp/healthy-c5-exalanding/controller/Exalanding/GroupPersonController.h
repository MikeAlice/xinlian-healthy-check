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
#ifndef _GROUPPERSON_CONTROLLER_
#define _GROUPPERSON_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/Exalanding/GroupPersonDTO.h"
#include "domain/vo/Exalanding/GroupPersonVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �ż���Ա����������ʾ�����ӿڵ�ʹ��
 */
class GroupPersonController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(GroupPersonController);
	// 3 ����ӿ�
public:

	// ���������ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("exalanding.post.insertInformation"), addGroupPerson, Uint64JsonVO::Wrapper);
	// ���������ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "Exalanding/add-groupPerson", addGroupPerson, BODY_DTO(GroupPersonDTO::Wrapper, dto), execAddGroupPerson(dto));
private:
	// ��ʾ��������
	Uint64JsonVO::Wrapper execAddGroupPerson(const GroupPersonDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _GROUPPERSON_CONTROLLER_
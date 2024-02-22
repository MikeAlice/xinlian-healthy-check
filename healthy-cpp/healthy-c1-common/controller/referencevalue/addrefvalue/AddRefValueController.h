#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2024/01/13

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
#ifndef _ADD_REF_VALUE_CONTROLLER_H_
#define _ADD_REF_VALUE_CONTROLLER_H_

#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/referencevalue/AddRefValueDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AddRefValueController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(AddRefValueController);
public: // ����ӿ�
	// ����ָ����Ŀ�ο�ֵ �����ˣ�����
	ENDPOINT_INFO(addRefValue) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("common.reference_value.controller.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/common/relationProject/AddReferenceValue", addRefValue, 
		BODY_DTO(AddRefValueDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddRefValue(dto));
	}
private: // ����ӿ�ִ�к���
	// ����ָ����Ŀ�ο�ֵ �����ˣ�����
	Uint64JsonVO::Wrapper execAddRefValue(const AddRefValueDTO::Wrapper & dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ADD_REF_VALUE_CONTROLLER_H_
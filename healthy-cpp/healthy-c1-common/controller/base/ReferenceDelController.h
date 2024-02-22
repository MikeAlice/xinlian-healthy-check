#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

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
#ifndef _REFERENCEDELCONTROLLER_H_
#define _REFERENCEDELCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/base/ReferenceDelVO.h"
#include "../../domain/dto/base/ReferenceDelDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ReferenceDelController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ReferenceDelController);
public://����ӿ�

	// 3.1 ����ɾ���ӿ�����
	//ENDPOINT_INFO(removeReference) {
	//	// �������ͷ��������Լ���Ȩ֧��
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("base.referenceDel.delete.summary"), Uint64JsonVO::Wrapper);
	//	// ��������·������˵��//�д���ȶ*
	//	API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("base.referenceDel.id"), "1", true);
	//}
	
	// ����Σ��ֵ�б��ѯ�ӿ�����
		ENDPOINT_INFO(removeReference) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("base.referenceDel.delete.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/base/removeReference", removeReference, PATH(String, id), execRemoveReference(id));
	
	ENDPOINT(API_M_DEL, "/base/removeReference", removeReference, BODY_DTO(ReferenceDelDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execRemoveReference(dto));
	};
	
	


private://����ӿ�ִ�к���
	Uint64JsonVO::Wrapper execRemoveReference(const ReferenceDelDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _REFERENCEDELCONTROLLER_H_
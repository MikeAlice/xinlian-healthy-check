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
#ifndef _DELETESAMPLE_CONTROLLER_
#define _DELETESAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/sample/DeleteSampleDTO.h"
#include "domain/vo/sample/DeleteSampleVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class DeleteSampleController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeleteSampleController);
	// 3 ����ӿ�
public:

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeSample) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("DeleteSample.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("sample.field.id"), "0c48696821bd11eca32bb42e99af990f", true);

	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sample/{id}", removeSample, PATH(String, id), execRemoveSample(id));

	// 3.3 ��ʾɾ������
	StringJsonVO::Wrapper execRemoveSample(const String& id);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
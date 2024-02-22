#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _DELETESAMPLE_DTO_
#define _DELETESAMPLE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class DeleteSampleDTO : public oatpp::DTO
{
	DTO_INIT(DeleteSampleDTO, DTO);
	//�Ƿ�ɾ��(0-δɾ����1-��ɾ��)del_flag
	DTO_FIELD(UInt32, del_flag);
	DTO_FIELD_INFO(del_flag) {
		info->description = ZH_WORDS_GETTER("DeleteSample.field.del_flag");
	}
	// ������
	DTO_FIELD(String, create_id);
	DTO_FIELD_INFO(create_id) {
		info->description = ZH_WORDS_GETTER("DeleteSample.field.create_id");
	}
	// ����ʱ��create_time
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("DeleteSample.field.create_time");
	}
	// �޸���update_id
	DTO_FIELD(String, update_id);
	DTO_FIELD_INFO(update_id) {
		info->description = ZH_WORDS_GETTER("DeleteSample.field.update_id");
	}
	// �޸�ʱ��update_time
	DTO_FIELD(String, update_time);
	DTO_FIELD_INFO(update_time) {
		info->description = ZH_WORDS_GETTER("DeleteSample.field.update_time");
	}
	// ɾ����delete_id
	DTO_FIELD(String, delete_id);
	DTO_FIELD_INFO(delete_id) {
		info->description = ZH_WORDS_GETTER("DeleteSample.field.delete_id");
	}
	// ɾ��ʱ��delete_time
	DTO_FIELD(String, delete_time);
	DTO_FIELD_INFO(delete_time) {
		info->description = ZH_WORDS_GETTER("DeleteSample.field.delete_time");
	}
	// ��������department_id
	DTO_FIELD(String, department_id);
	DTO_FIELD_INFO(department_id) {
		info->description = ZH_WORDS_GETTER("DeleteSample.field.department_id");
	}
};

/**
 * ʾ����ҳ�������
 */
class DeleteSamplePageDTO : public PageDTO<DeleteSampleDTO::Wrapper>
{
	DTO_INIT(DeleteSamplePageDTO, PageDTO<DeleteSampleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: luoluo
 @Date: 2024/1/21 10:59:38

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
#ifndef _THREELEVCHECK_DTO_
#define _THREELEVCHECK_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������˴������
 */
class ThreeLevCheckDTO : public oatpp::DTO
{
	DTO_INIT(ThreeLevCheckDTO, DTO);
	// �������ݱ� ����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("threelevcheck.field.id"));
	// ����id
	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("threelevcheck.field.orderId"));
	// ���󼶱�
	API_DTO_FIELD_DEFAULT(String, auditLevel, ZH_WORDS_GETTER("threelevcheck.field.auditLevel"));
	// ��˽�������
	API_DTO_FIELD_DEFAULT(String, conclusionDate, ZH_WORDS_GETTER("threelevcheck.field.conclusionDate"));
	//�쵼����������
	API_DTO_FIELD_DEFAULT(String, approvalPersonInCharge, ZH_WORDS_GETTER("threelevcheck.field.approvalPersonInCharge"));
	// �Ƿ�ͬ����׼
	API_DTO_FIELD_DEFAULT(String, isAgree, ZH_WORDS_GETTER("threelevcheck.field.isAgree"));
	//��ͬ����׼��ԭ��
	API_DTO_FIELD_DEFAULT(String, reasonNoAgree, ZH_WORDS_GETTER("threelevcheck.field.reasonNoAgree"));
	//�����׼����
	API_DTO_FIELD_DEFAULT(String, approvalDate, ZH_WORDS_GETTER("threelevcheck.field.approvalDate"));
	//������
	API_DTO_FIELD_DEFAULT(String, createId, ZH_WORDS_GETTER("threelevcheck.field.createId"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("threelevcheck.field.createTime"));
	//�޸���
	API_DTO_FIELD_DEFAULT(String, updateId, ZH_WORDS_GETTER("threelevcheck.field.updateId"));
	//�޸�ʱ��
	API_DTO_FIELD_DEFAULT(String, updateTime, ZH_WORDS_GETTER("threelevcheck.field.updateTime"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_THREELEVCHECK_DTO_
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: lenya~
 @Date: 2024/1/18

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
#ifndef  _DETAILQUERY_
#define  _DETAILQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ������ϸ��ҳ��ѯ
 */
class InquiryDetailQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(InquiryDetailQuery, PageQuery);
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("inquiry.field.Id"));
	// �������
	API_DTO_FIELD_DEFAULT(UInt64, workYear, ZH_WORDS_GETTER("inquiry.field.workYear"));
	// �����¶�
	API_DTO_FIELD_DEFAULT(UInt64, workMonth, ZH_WORDS_GETTER("inquiry.field.workMonth"));
	// ���״��
	API_DTO_FIELD_DEFAULT(String, isMarry, ZH_WORDS_GETTER("inquiry.field.isMarry"));
	//��������
	API_DTO_FIELD_DEFAULT(UInt64, exposureWorkYear, ZH_WORDS_GETTER("inquiry.field.exposureWorkYear"));
	//��������
	API_DTO_FIELD_DEFAULT(UInt64, exposureWorkMonth, ZH_WORDS_GETTER("inquiry.field.exposureWorkMonth"));

	//�Ǳ���

	//�Ļ��̶�
	API_DTO_FIELD_DEFAULT(String, education, ZH_WORDS_GETTER("inquiry.field.education"));
	//��ͥ��ַ
	API_DTO_FIELD_DEFAULT(String, familyAddress, ZH_WORDS_GETTER("inquiry.field.familyAddress"));
	//��������
	API_DTO_FIELD_DEFAULT(String, workTypeText, ZH_WORDS_GETTER("inquiry.field.workTypeText"));
	//������������
	API_DTO_FIELD_DEFAULT(String, workName, ZH_WORDS_GETTER("inquiry.field.workName"));
	//��������
	API_DTO_FIELD_DEFAULT(String, department, ZH_WORDS_GETTER("inquiry.field.department"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
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
 * 获取问诊明细分页查询
 */
class InquiryDetailQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(InquiryDetailQuery, PageQuery);
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("inquiry.field.Id"));
	// 工龄年段
	API_DTO_FIELD_DEFAULT(UInt64, workYear, ZH_WORDS_GETTER("inquiry.field.workYear"));
	// 工龄月段
	API_DTO_FIELD_DEFAULT(UInt64, workMonth, ZH_WORDS_GETTER("inquiry.field.workMonth"));
	// 结婚状况
	API_DTO_FIELD_DEFAULT(String, isMarry, ZH_WORDS_GETTER("inquiry.field.isMarry"));
	//按需年龄
	API_DTO_FIELD_DEFAULT(UInt64, exposureWorkYear, ZH_WORDS_GETTER("inquiry.field.exposureWorkYear"));
	//按需月龄
	API_DTO_FIELD_DEFAULT(UInt64, exposureWorkMonth, ZH_WORDS_GETTER("inquiry.field.exposureWorkMonth"));

	//非必须

	//文化程度
	API_DTO_FIELD_DEFAULT(String, education, ZH_WORDS_GETTER("inquiry.field.education"));
	//家庭地址
	API_DTO_FIELD_DEFAULT(String, familyAddress, ZH_WORDS_GETTER("inquiry.field.familyAddress"));
	//工种名称
	API_DTO_FIELD_DEFAULT(String, workTypeText, ZH_WORDS_GETTER("inquiry.field.workTypeText"));
	//工种其他名称
	API_DTO_FIELD_DEFAULT(String, workName, ZH_WORDS_GETTER("inquiry.field.workName"));
	//所属部门
	API_DTO_FIELD_DEFAULT(String, department, ZH_WORDS_GETTER("inquiry.field.department"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
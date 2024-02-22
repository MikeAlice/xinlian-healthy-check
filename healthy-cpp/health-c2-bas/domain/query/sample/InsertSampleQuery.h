#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _InsertSample_QUERY_
#define _InsertSample_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//InsertSampleQuery
/**
 * 样本列表分页查询实体
 */
class InsertSampleQuery : public PageQuery
{
	DTO_INIT(InsertSampleQuery, PageQuery);

	//查询类型
	API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("sample.obsl.type"));
	//名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("sample.obsl.name"));
	//规格
	API_DTO_FIELD_DEFAULT(String, spec, ZH_WORDS_GETTER("sample.obsl.spec"));
	//样本代码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("sample.obsl.code"));
	//是否打印
	API_DTO_FIELD_DEFAULT(UInt32, is_print, ZH_WORDS_GETTER("sample.obsl.is_print"));
	//容量
	API_DTO_FIELD_DEFAULT(String, capacity, ZH_WORDS_GETTER("sample.obsl.capacity"));
	// 条码份数
	API_DTO_FIELD_DEFAULT(UInt32, barcode_num, ZH_WORDS_GETTER("sample.obsl.barcode_num"));
	//是否采血
	API_DTO_FIELD_DEFAULT(UInt32, need_take_blood, ZH_WORDS_GETTER("sample.obsl.need_take_blood"));
	//排序
	API_DTO_FIELD_DEFAULT(Float32, order_num, ZH_WORDS_GETTER("sample.obsl.order_num"));
	//关联码
	API_DTO_FIELD_DEFAULT(String, liscode, ZH_WORDS_GETTER("sample.obsl.liscode"));

	//API_DTO_FIELD_DEFAULT(UInt32, del_flag, ZH_WORDS_GETTER("sample.obsl.del_flag"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
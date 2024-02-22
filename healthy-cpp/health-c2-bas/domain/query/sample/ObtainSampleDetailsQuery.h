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
#ifndef _OBTAIN_SAMPLE_DETAILS_QUERY_ 
#define _OBTAIN_SAMPLE_DETAILS_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class ObtainSampleDetailsQuery : public PageQuery
{
	DTO_INIT(ObtainSampleDetailsQuery, PageQuery);
	//名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sampleDetails.field.name");
	}
	//条码份数
	DTO_FIELD(UInt32, barcode_num);
	DTO_FIELD_INFO(barcode_num) {
		info->description = ZH_WORDS_GETTER("sampleDetails.field.barcode_num");
	}
	//规格
	DTO_FIELD(String, spec);
	DTO_FIELD_INFO(spec) {
		info->description = ZH_WORDS_GETTER("sampleDetails.field.spec");
	}
	//是否采血
	DTO_FIELD(UInt32, need_take_blood);
	DTO_FIELD_INFO(need_take_blood) {
		info->description = ZH_WORDS_GETTER("sampleDetails.field.need_take_blood");
	}
	//标本代码
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("sampleDetails.field.code");
	}
	//排序
	DTO_FIELD(Float32, order_num);
	DTO_FIELD_INFO(order_num) {
		info->description = ZH_WORDS_GETTER("sampleDetails.field.order_num");
	}
	//是否打印
	DTO_FIELD(UInt32, is_print);
	DTO_FIELD_INFO(is_print) {
		info->description = ZH_WORDS_GETTER("sampleDetails.field.is_print");
	}
	//关联码
	DTO_FIELD(String, liscode);
	DTO_FIELD_INFO(liscode) {
		info->description = ZH_WORDS_GETTER("sampleDetails.field.liscode");
	}
	//容量
	DTO_FIELD(String, capacity);
	DTO_FIELD_INFO(capacity) {
		info->description = ZH_WORDS_GETTER("sampleDetails.field.capacity");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
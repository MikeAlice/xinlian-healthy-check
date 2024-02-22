// #pragma once
// /*
//  Copyright Zero One Star. All rights reserved.
// 
//  @Author: dragon
//  @Date: 2022/10/25 11:36:29
// 
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
// 
// 	  https://www.apache.org/licenses/LICENSE-2.0
// 
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
// */
// #ifndef _ORDERVIEWAPPROVAL_QUERY_
// #define _ORDERVIEWAPPROVAL_QUERY_
// 
// #include "../../GlobalInclude.h"
// #include"../../lib-oatpp/include/domain/query/PageQuery.h"
// #include OATPP_CODEGEN_BEGIN(DTO)
// class Orderviewapprovalquery :public oatpp::DTO {
// 
// 	DTO_INIT(Orderviewapprovalquery, PageQuery);
// 	//查询类型
// 	DTO_FIELD(String, type);
// 	DTO_FIELD_INFO(type) {
// 		info->description = ZH_WORDS_GETTER("order.field.type");
// 	}
// 	//API_DTO_FIELD_DEFAULT(string, type, ZH_WORDS_GETTER("order.field.type"));
// 	//单位名称
// 	DTO_FIELD(String, name);
// 	DTO_FIELD_INFO(name) {
// 		info->description = ZH_WORDS_GETTER("order.field.name");
// 	}
// 	//API_DTO_FIELD_DEFAULT(string, name, ZH_WORDS_GETTER("order.field.name"));
// 	//体检日期
// 	DTO_FIELD(String, delivery_time);
// 	DTO_FIELD_INFO(delivery_time) {
// 		info->description = ZH_WORDS_GETTER("order.field.delivery_time");
// 	}
// 	//API_DTO_FIELD_DEFAULT(string, delivery_time, ZH_WORDS_GETTER("order.field.delivery_time"));
// 	//审核状态
// 	DTO_FIELD(String, status);
// 	DTO_FIELD_INFO(status) {
// 		info->description = ZH_WORDS_GETTER("order.field.status");
// 	}
// 	//API_DTO_FIELD_DEFAULT(string, status, ZH_WORDS_GETTER("order.field.status"));
// 
// };
// #include OATPP_CODEGEN_END(DTO)
// #endif
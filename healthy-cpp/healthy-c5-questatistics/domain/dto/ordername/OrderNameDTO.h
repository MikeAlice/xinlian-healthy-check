#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 会跑的鱼
 @Date: 2024/1/19 17:36:29

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
#ifndef _ORDERNAME_DTO_
#define _ORDERNAME_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取体检单位订单名称传输对象
 */
class  OrderNameDTO : public oatpp::DTO
{
	DTO_INIT(OrderNameDTO, DTO);
	// 体检编号
	DTO_FIELD(String, checkId);
	DTO_FIELD_INFO(checkId) {
		info->description = ZH_WORDS_GETTER("ordername.field.checkId");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("ordername.field.name");
	}
	// 年龄
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("ordername.field.age");
	}
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("ordername.field.sex");
	}

	//身份证号
	DTO_FIELD(String, idCard);
	DTO_FIELD_INFO(idCard) {
		info->description = ZH_WORDS_GETTER("ordername.field.idCard");
	}

	//体检状态
	DTO_FIELD(String, checkState);
	DTO_FIELD_INFO(checkState) {
		info->description = ZH_WORDS_GETTER("ordername.field.checkState");
	}

	//审核状态/
	DTO_FIELD(Int32, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("ordername.field.state");
	}

	//危害因素
	DTO_FIELD(String, dangerFactors);
	DTO_FIELD_INFO(dangerFactors) {
		info->description = ZH_WORDS_GETTER("ordername.field.dangerFactors");
	}

	//体检日期
	DTO_FIELD(String, checkDate);
	DTO_FIELD_INFO(checkDate) {
		info->description = ZH_WORDS_GETTER("ordername.field.checkDate");
	}

	//体检结论
	DTO_FIELD(String, checkResults);
	DTO_FIELD_INFO(checkResults) {
		info->description = ZH_WORDS_GETTER("ordername.field.checkResults");
	}
	//在岗状态
	DTO_FIELD(String, dutyState);
	DTO_FIELD_INFO(dutyState) {
		info->description = ZH_WORDS_GETTER("ordername.field.dutyState");
	}
	////未完成项目
	//DTO_FIELD(String, unfinishedProject);
	//DTO_FIELD_INFO(unfinishedProject) {
	//	info->description = ZH_WORDS_GETTER("ordername.field.unfinishedProject");
	//}

	//单位名称
	DTO_FIELD(String, unitName);
	DTO_FIELD_INFO(unitName) {
		info->description = ZH_WORDS_GETTER("ordername.field.unitName");
	}
};

/**
 * 获取体检单位订单名称分页传输对象
 */
class  OrderNamePageDTO : public PageDTO< OrderNameDTO::Wrapper>
{
	DTO_INIT(OrderNamePageDTO, PageDTO< OrderNameDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RESULTSLIST_DTO_
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/01/14 18:44:38

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
#ifndef _UNITREPORTDTO_H_
#define _UNITREPORTDTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取单位报告
 * 负责人：。好
 */
class UnitReportDTO : public oatpp::DTO
{
	DTO_INIT(UnitReportDTO, DTO)
	// 报告编号
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.unit-code");
	}
	// 体检单位
	DTO_FIELD(String, physical_unit);
	DTO_FIELD_INFO(physical_unit) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.physical-unit");
	}
	// 体检日期
	DTO_FIELD(String, physical_date);
	DTO_FIELD_INFO(physical_date) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.physical-date");
	}
	// 体检项目
	DTO_FIELD(String, physical_project);
	DTO_FIELD_INFO(physical_project) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.physical-project");
	}
	// 体检意见
	DTO_FIELD(String, concluding_observations);
	DTO_FIELD_INFO(concluding_observations) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.concluding-observations");
	}
	// 体检类型
	DTO_FIELD(String, physical_type);
	DTO_FIELD_INFO(physical_type) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.physical-type");
	}
	// 委托单位
	DTO_FIELD(String, entrust_unit);
	DTO_FIELD_INFO(entrust_unit) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.entrust-unit");
	}
	// 体检人数
	DTO_FIELD(String, physical_number);
	DTO_FIELD_INFO(physical_number) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.physical-number");
	}
	// 评论依据
	DTO_FIELD(String, evaluation_basis);
	DTO_FIELD_INFO(evaluation_basis) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.evaluation-basis");
	}
public:
	UnitReportDTO() {
		code = "1";
		physical_unit = "1";
		physical_date = "1";
	}
};

/**
 * 获取单位报告列表
 * 负责人：。好
 */
class UnitReportListDTO : public oatpp::DTO
{
	DTO_INIT(UnitReportListDTO, DTO)
	// 数据列表
	API_DTO_FIELD(List<UnitReportDTO::Wrapper>, itemList, "list", false, {});
public:
	void push(UnitReportDTO::Wrapper item) {
		this->itemList->push_back(item);
	}
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITREPORTDTO_H_
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
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
 * ��ȡ��λ����
 * �����ˣ�����
 */
class UnitReportDTO : public oatpp::DTO
{
	DTO_INIT(UnitReportDTO, DTO)
	// ������
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.unit-code");
	}
	// ��쵥λ
	DTO_FIELD(String, physical_unit);
	DTO_FIELD_INFO(physical_unit) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.physical-unit");
	}
	// �������
	DTO_FIELD(String, physical_date);
	DTO_FIELD_INFO(physical_date) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.physical-date");
	}
	// �����Ŀ
	DTO_FIELD(String, physical_project);
	DTO_FIELD_INFO(physical_project) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.physical-project");
	}
	// ������
	DTO_FIELD(String, concluding_observations);
	DTO_FIELD_INFO(concluding_observations) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.concluding-observations");
	}
	// �������
	DTO_FIELD(String, physical_type);
	DTO_FIELD_INFO(physical_type) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.physical-type");
	}
	// ί�е�λ
	DTO_FIELD(String, entrust_unit);
	DTO_FIELD_INFO(entrust_unit) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.entrust-unit");
	}
	// �������
	DTO_FIELD(String, physical_number);
	DTO_FIELD_INFO(physical_number) {
		info->description = ZH_WORDS_GETTER("UnitReport.field.physical-number");
	}
	// ��������
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
 * ��ȡ��λ�����б�
 * �����ˣ�����
 */
class UnitReportListDTO : public oatpp::DTO
{
	DTO_INIT(UnitReportListDTO, DTO)
	// �����б�
	API_DTO_FIELD(List<UnitReportDTO::Wrapper>, itemList, "list", false, {});
public:
	void push(UnitReportDTO::Wrapper item) {
		this->itemList->push_back(item);
	}
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITREPORTDTO_H_
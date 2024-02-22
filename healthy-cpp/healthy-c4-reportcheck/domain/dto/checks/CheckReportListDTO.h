#pragma once
#ifndef _CHECKLISTDTO_H_
#define _CHECKLISTDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 报告列表数据实体
* 负责人：Z
*/
class CheckReportListDTO : public oatpp::DTO
{
	DTO_INIT(CheckReportListDTO, DTO);
	// 唯一编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("report.field.id"));

	// 姓名
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("report.field.name"));

	// 性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("report.field.sex"));

	// 年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("report.field.age"));

	// 是否过审
	API_DTO_FIELD_DEFAULT(Boolean, statu, ZH_WORDS_GETTER("report.field.statu"));

	// 是否打印
	API_DTO_FIELD_DEFAULT(Boolean, print_state, ZH_WORDS_GETTER("report.field.printState"));

	// 是否零星体检
	API_DTO_FIELD_DEFAULT(Boolean, sporadic_physical, ZH_WORDS_GETTER("report.field.sporadicPhysical"));

};
/*
	报告列表分页实体
	负责人 Z
*/
class CheckReportListPageDTO : public PageDTO<CheckReportListDTO::Wrapper> {
	DTO_INIT(CheckReportListPageDTO, PageDTO<CheckReportListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CHECKLISTDTO_H_
#pragma once

#ifndef _ReportList_DTO_
#define _ReportList_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报告列表传输对象
 */
class ReportListDTO : public oatpp::DTO
{
	DTO_INIT(ReportListDTO, DTO);

	// 体检编号
	DTO_FIELD(String, test_num);
	DTO_FIELD_INFO(test_num) {
		info->description = ZH_WORDS_GETTER("reportlist.field.test_num");
	}
	// 身份证号
	DTO_FIELD(String, id_card);
	DTO_FIELD_INFO(id_card) {
		info->description = ZH_WORDS_GETTER("reportlist.field.id_card");
	}
	// 姓名
	DTO_FIELD(String, person_name);
	DTO_FIELD_INFO(person_name) {
		info->description = ZH_WORDS_GETTER("reportlist.field.person_name");
	}
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("reportlist.field.sex");
	}
	// 年龄
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("reportlist.field.age");
	}
	// 体检日期
	DTO_FIELD(String, check_date);
	DTO_FIELD_INFO(check_date) {
		info->description = ZH_WORDS_GETTER("reportlist.field.check_date");
	}
	// 是否合格 需要询问！！！
	DTO_FIELD(String, check_result);
	DTO_FIELD_INFO(check_result) {
		info->description = ZH_WORDS_GETTER("reportlist.field.check_result");
	}
	
	// 体检单位
	DTO_FIELD(String, physical_unit);
	DTO_FIELD_INFO(physical_unit) {
		info->description = ZH_WORDS_GETTER("reportlist.field.physical_unit");
	}

	// 审核状态
	DTO_FIELD(Int32, statu);
	DTO_FIELD_INFO(statu) {
		info->description = ZH_WORDS_GETTER("reportlist.field.statu");
	}
};

/**
 * 报告列表分页传输对象
 */
class ReportListPageDTO : public PageDTO<ReportListDTO::Wrapper>
{
	DTO_INIT(ReportListPageDTO, PageDTO<ReportListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif
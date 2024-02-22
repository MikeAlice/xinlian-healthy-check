#pragma once
#ifndef _CHECKQUERY_H_
#define _CHECKQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/*
	这是报告审核查询
	负责人 Z
*/
class CheckReportQuery : public PageQuery
{
	DTO_INIT(CheckReportQuery, PageQuery);
	// 查询类型
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("report.field.type"));

	// 姓名
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("report.field.name"));

	// 订单编号
	API_DTO_FIELD_DEFAULT(String, order_id, ZH_WORDS_GETTER("report.field.orderId"));

	// 体检编号
	API_DTO_FIELD_DEFAULT(String, test_num, ZH_WORDS_GETTER("report.field.testNum"));

	// 单位名称
	API_DTO_FIELD_DEFAULT(String, unit_id, ZH_WORDS_GETTER("report.field.unitId"));

	// 是否过审
	API_DTO_FIELD_DEFAULT(Boolean, statu, ZH_WORDS_GETTER("report.field.statu"));

	// 是否复查
	API_DTO_FIELD_DEFAULT(Boolean, is_recheck, ZH_WORDS_GETTER("report.field.isRecheck"));

	// 查询开始日期
	API_DTO_FIELD_DEFAULT(String, stardate, ZH_WORDS_GETTER("report.field.starDate"));

	//查询结束日期
	API_DTO_FIELD_DEFAULT(String, enddate, ZH_WORDS_GETTER("report.field.endDate"));

}; 

#include OATPP_CODEGEN_END(DTO)
#endif //!_CHECKQUERY_H_
#pragma once
#ifndef _MEDEXAMPRINTREPORT_H_
#define _MEDEXAMPRINTREPORT_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报告打印分页查询体检人员
 * 负责人：小智
 */
class MedExamPrintReportQuery : public PageQuery
{
	DTO_INIT(MedExamPrintReportQuery, PageQuery);
	// 体检类型
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("print.field.type"));
	// 姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("print.field.name"));
	// 订单编号
	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("print.field.orderId"));
	// 体检编号
	API_DTO_FIELD_DEFAULT(String, testNum, ZH_WORDS_GETTER("print.field.testNum"));
	// 单位名称
	API_DTO_FIELD_DEFAULT(String, dept, ZH_WORDS_GETTER("print.field.dept"));
	// 开始日期
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("print.field.startDate"));
	// 结束日期
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("print.field.endDate"));
	// 是否复查
	API_DTO_FIELD_DEFAULT(Boolean, isRecheck, ZH_WORDS_GETTER("print.field.isRecheck"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEDEXAMPRINTR      EPORT_H_
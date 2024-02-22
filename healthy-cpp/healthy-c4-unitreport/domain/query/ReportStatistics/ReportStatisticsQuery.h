#pragma once

#ifndef _REPORTSTATISTICSQUERY_H_
#define _REPORTSTATISTICSQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

/*
* 统计表数据实体
*/
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询用户信息的数据传输模型
 */
class ReportStatisticsQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(ReportStatisticsQuery, PageQuery);
	//订单编号
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("unitreport.order.code"));
	////统计表类型用数字来表示1："体检人员汇总表" 2："复查人员汇总表" 3："复查结果汇总表"
	//API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("unitreport.summaryTable.type"));
};

#include OATPP_CODEGEN_END(DTO)

#endif


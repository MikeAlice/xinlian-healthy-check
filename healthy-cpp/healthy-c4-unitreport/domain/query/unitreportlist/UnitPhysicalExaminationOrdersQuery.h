#pragma once

#ifndef _UNITPHYSICALEXAMINATIONORDERSQUERY_H_
#define _UNITPHYSICALEXAMINATIONORDERSQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

/*
* 体检单位分页订单名称列表数据实体
*/
#include OATPP_CODEGEN_BEGIN(DTO)

class UnitPhysicalExaminationOrdersQuery : public PageQuery
{
	//定义初始化
	DTO_INIT(UnitPhysicalExaminationOrdersQuery, PageQuery);
	//单位名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unitreport.unit.name"));
	//查找订单签订时间的开始时间
	API_DTO_FIELD_DEFAULT(String, beginTime, ZH_WORDS_GETTER("unitreport.order.signingTime"));
	//查找订单签订时间的结束时间
	API_DTO_FIELD_DEFAULT(String, endTime, ZH_WORDS_GETTER("unitreport.order.signingTime"));
};

#include OATPP_CODEGEN_END(DTO)

#endif


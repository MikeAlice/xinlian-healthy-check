#pragma once

#ifndef _UNITLISTDTO_
#define _UNITLISTDTO_

#include "../../GlobalInclude.h"

/*
* 体检单位订单名称列表数据对象实体
*/

#include OATPP_CODEGEN_BEGIN(DTO)

class UnitListDTO : public oatpp::DTO
{
	//定义初始化
	DTO_INIT(UnitListDTO, DTO);
	//单位名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unitreport.unit.name"));
	//订单编号
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("unitreport.order.code"));
	//订单日期
	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("unitreport.order.signingTime"));
	//是否上报
	API_DTO_FIELD_DEFAULT(String, Escalation, "");
	//检测类型
	API_DTO_FIELD_DEFAULT(String, detectionType, "");
};

/*
* 单位分页列表数据实体
*/
class UnitListPageDTO : public PageDTO<UnitListDTO::Wrapper>
{
	//定义初始化
	DTO_INIT(UnitListPageDTO, PageDTO<UnitListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif
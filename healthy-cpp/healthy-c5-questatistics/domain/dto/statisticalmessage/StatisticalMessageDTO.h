#pragma once

#ifndef _STATISTICALMESSAGEDTO_H_
#define _STATISTICALMESSAGEDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*单位列表传输对象实体
*/

class StatisticalMessageDTO : public oatpp::DTO
{
	DTO_INIT(StatisticalMessageDTO, DTO);
	//唯一编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("list.field.id"));
	//体检状态
	API_DTO_FIELD_DEFAULT(UInt32, isPass, ZH_WORDS_GETTER("statistica.rate.isPass"));
};

/**
*单位列表分页数据实体
*/

class StatisticalMessagePageDTO :public PageDTO < StatisticalMessageDTO::Wrapper > {
	DTO_INIT(StatisticalMessagePageDTO, PageDTO < StatisticalMessageDTO::Wrapper >);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_JoinPersonListDTO_H_
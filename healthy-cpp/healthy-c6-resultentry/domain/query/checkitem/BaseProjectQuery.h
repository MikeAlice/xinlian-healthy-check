#pragma once
#ifndef _BASEPROJECT_H_
#define _BASEPROJECT_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
*定义一个查询组合项目内基础项目体检结果的传输模型
*/

class BaseProjectQuery : public PageQuery
{
	DTO_INIT(BaseProjectQuery, PageQuery);
	//所选的组合项目名称
	API_DTO_FIELD_DEFAULT(String, portfolioId, ZH_WORDS_GETTER("checkitem.portfolio.id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BASEPROJECT_H_

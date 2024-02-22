#pragma once
#ifndef _JobNameListQuery_H_
#define _JobNameListQuery_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class JobNameListQuery : public PageQuery
{
	DTO_INIT(JobNameListQuery, PageQuery);
	API_DTO_FIELD(String, keyword, ZH_WORDS_GETTER("jobnamelist.field.keyword"), false, "");
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTACTNAMEQUERY_H_
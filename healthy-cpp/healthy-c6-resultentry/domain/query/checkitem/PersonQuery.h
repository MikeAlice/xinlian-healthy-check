#pragma once
#ifndef _PERSON_H_
#define _PERSON_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
*定义一个查询体检人员参与的组合项目体检数据的传输模型
*/

class PersonQuery : public PageQuery
{
	DTO_INIT(PersonQuery, PageQuery);
	//人员编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("checkitem.person.id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSON_H_
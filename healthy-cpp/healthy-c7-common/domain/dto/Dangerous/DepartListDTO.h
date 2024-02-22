#pragma once
#ifndef _DEPARTLISTDTO_H_
#define _DEPARTLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DepartListDTO : public oatpp :: DTO{
	DTO_INIT(DepartListDTO, DTO);
//科室名称
API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("departList.field.officeName"));
//项目名称
API_DTO_FIELD_DEFAULT(String, projectName, ZH_WORDS_GETTER("departList.field.projectName"));
//结果
API_DTO_FIELD_DEFAULT(String, result, ZH_WORDS_GETTER("departList.field.result"));
//参考范围
API_DTO_FIELD_DEFAULT(String, scope, ZH_WORDS_GETTER("departList.field.scope"));
};

class DepartListPageDTO : public PageDTO<DepartListDTO::Wrapper> {
	DTO_INIT(DepartListPageDTO, PageDTO<DepartListDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITQUERY_H_
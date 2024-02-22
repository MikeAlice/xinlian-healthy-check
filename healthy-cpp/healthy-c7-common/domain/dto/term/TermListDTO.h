#pragma once
#ifndef  _TERMLISTDTO_H_
#define _TERMLISTDTO_H_
#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)
/**
*单位列表传输数据对象实体
*/
class TermListDTO : public oatpp::DTO
{
	DTO_INIT(TermListDTO, DTO);
	//主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("term.field.id"));
	//ID
	API_DTO_FIELD_DEFAULT(String, officeId, ZH_WORDS_GETTER("term.field.officeId"));
	//危害因素
	API_DTO_FIELD_DEFAULT(String, hazardFactorsText, ZH_WORDS_GETTER("term.field.hazardFactorsText"));
	// 类型
	API_DTO_FIELD_DEFAULT(String, inspectType, ZH_WORDS_GETTER("term.field.inspectType"));
	// 内容
	API_DTO_FIELD_DEFAULT(String, content, ZH_WORDS_GETTER("term.field.content"));
	//在岗状态
	API_DTO_FIELD_DEFAULT(String, workStateText, ZH_WORDS_GETTER("term.field.workStateText"));
};
/**
 * 单位列表分页数据实体
 */
class TermListPageDTO :public PageDTO< TermListDTO::Wrapper> {
	DTO_INIT(TermListPageDTO, PageDTO< TermListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif
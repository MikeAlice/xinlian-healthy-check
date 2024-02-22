#pragma once
#ifndef _NAMELISTDTO_H_
#define _NAMELISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个合同关键信息传输对象
 */
class NameListDTO : public oatpp::DTO
{
	DTO_INIT(NameListDTO, DTO);
	// 签订时间
	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("contract.field.signingTime"));
	// 委托单位
	API_DTO_FIELD_DEFAULT(String, groupUnitName, ZH_WORDS_GETTER("contract.field.groupUnitName"));
	//审核状态
	API_DTO_FIELD_DEFAULT(UInt32, auditState, ZH_WORDS_GETTER("contract.field.auditState"));
};

/**
 * 定义一个合同关键信息分页传输对象
 */
class NameListPageDTO : public PageDTO<NameListDTO::Wrapper>
{
	DTO_INIT(NameListPageDTO, PageDTO<NameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_
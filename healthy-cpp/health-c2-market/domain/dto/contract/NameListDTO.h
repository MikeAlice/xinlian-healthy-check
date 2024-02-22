#pragma once
#ifndef _NAMELISTDTO_H_
#define _NAMELISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ����ͬ�ؼ���Ϣ�������
 */
class NameListDTO : public oatpp::DTO
{
	DTO_INIT(NameListDTO, DTO);
	// ǩ��ʱ��
	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("contract.field.signingTime"));
	// ί�е�λ
	API_DTO_FIELD_DEFAULT(String, groupUnitName, ZH_WORDS_GETTER("contract.field.groupUnitName"));
	//���״̬
	API_DTO_FIELD_DEFAULT(UInt32, auditState, ZH_WORDS_GETTER("contract.field.auditState"));
};

/**
 * ����һ����ͬ�ؼ���Ϣ��ҳ�������
 */
class NameListPageDTO : public PageDTO<NameListDTO::Wrapper>
{
	DTO_INIT(NameListPageDTO, PageDTO<NameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_
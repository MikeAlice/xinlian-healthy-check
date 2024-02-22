#pragma once
#ifndef  _TERMLISTDTO_H_
#define _TERMLISTDTO_H_
#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)
/**
*��λ�б������ݶ���ʵ��
*/
class TermListDTO : public oatpp::DTO
{
	DTO_INIT(TermListDTO, DTO);
	//����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("term.field.id"));
	//ID
	API_DTO_FIELD_DEFAULT(String, officeId, ZH_WORDS_GETTER("term.field.officeId"));
	//Σ������
	API_DTO_FIELD_DEFAULT(String, hazardFactorsText, ZH_WORDS_GETTER("term.field.hazardFactorsText"));
	// ����
	API_DTO_FIELD_DEFAULT(String, inspectType, ZH_WORDS_GETTER("term.field.inspectType"));
	// ����
	API_DTO_FIELD_DEFAULT(String, content, ZH_WORDS_GETTER("term.field.content"));
	//�ڸ�״̬
	API_DTO_FIELD_DEFAULT(String, workStateText, ZH_WORDS_GETTER("term.field.workStateText"));
};
/**
 * ��λ�б��ҳ����ʵ��
 */
class TermListPageDTO :public PageDTO< TermListDTO::Wrapper> {
	DTO_INIT(TermListPageDTO, PageDTO< TermListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif
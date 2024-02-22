#pragma once
#ifndef _CHECKLISTDTO_H_
#define _CHECKLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CheckListDTO : public oatpp::DTO
{
	DTO_INIT(CheckListDTO, DTO);
	//��Ŀ���ƣ���ȷ��д��û�����������ݿ�t_lis��ġ����͡���item����
	API_DTO_FIELD_DEFAULT(String, item, ZH_WORDS_GETTER("check.field.item"));
	//ԭ��
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("check.field.id_card"));
	//�ۿ�
	API_DTO_FIELD_DEFAULT(UInt32, discount, ZH_WORDS_GETTER("check.field.discount"));
	//�ۿۼ�
	API_DTO_FIELD_DEFAULT(Float64, discount_price, ZH_WORDS_GETTER("check.field.discount_price"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, physical_type, ZH_WORDS_GETTER("check.field.physical_type"));

};

/**
 * �����Ա�����б��ҳ�������
 */
class CheckListPageDTO : public PageDTO<CheckListDTO::Wrapper>
{
	DTO_INIT(CheckListPageDTO, PageDTO<CheckListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CHECKLISTDTO_H_
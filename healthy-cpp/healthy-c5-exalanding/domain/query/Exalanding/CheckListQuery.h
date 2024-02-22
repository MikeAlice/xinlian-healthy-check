#pragma once
#ifndef _CHECKLISTQUERY_H_
#define _CHECKLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * �����Ա�����б��ҳ��ѯ����
 */

class CheckListQuery : public PageQuery
{
	DTO_INIT(CheckListQuery, PageQuery);
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

#include OATPP_CODEGEN_END(DTO)

#endif // !_CHECKLISTQUERY_H_
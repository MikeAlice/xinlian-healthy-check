#pragma once

#ifndef _UNITLISTQUERY_H_
#define _UNITLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��λ��ҳ��ѯʵ��
 */
class UnitListQuery : public PageQuery
{
	DTO_INIT(UnitListQuery, PageQuery);
	//��λ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unit.field.name"));
	//�������
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unit.field.physical_type"));
	//ͳһ������ô���
	API_DTO_FIELD_DEFAULT(String, uscc, ZH_WORDS_GETTER("unit.field.uscc"));
	//�����ϵ��
	API_DTO_FIELD_DEFAULT(String, linkMan2, ZH_WORDS_GETTER("unit.field.link_man2"));
	//�����ϵ�˵绰
	API_DTO_FIELD_DEFAULT(String, linkPhone2, ZH_WORDS_GETTER("unit.field.link_phone2"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITLISTQUERY_H_
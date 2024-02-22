#pragma once

#ifndef _UNITLISTDTO_H_
#define _UNITLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��λ�б������ݶ���ʵ��
 */
class UnitListDTO : public oatpp::DTO
{
	DTO_INIT(UnitListDTO, DTO);
	//��λID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unit.field.id"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unit.field.name"));
	//�������
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unit.field.physical_type"));
	//ͳһ������ô���
	API_DTO_FIELD_DEFAULT(String, uscc, ZH_WORDS_GETTER("unit.field.uscc"));
	//��ҵ��������
	API_DTO_FIELD_DEFAULT(String, industryName, ZH_WORDS_GETTER("unit.field.industry_name"));
	//����������ַ
	API_DTO_FIELD_DEFAULT(String, regionName, ZH_WORDS_GETTER("unit.field.region_name"));
	//������������
	API_DTO_FIELD_DEFAULT(String, economicTypeName, ZH_WORDS_GETTER("unit.field.economic_type_name"));
	//��ҵ��ģ����
	API_DTO_FIELD_DEFAULT(String, businessScaleName, ZH_WORDS_GETTER("unit.field.business_scale_name"));
	//�����ϵ��
	API_DTO_FIELD_DEFAULT(String, linkMan2, ZH_WORDS_GETTER("unit.field.link_man2"));
	//�����ϵ�˵绰
	API_DTO_FIELD_DEFAULT(String, linkPhone2, ZH_WORDS_GETTER("unit.field.link_phone2"));
};

/**
 * ��λ�б��ҳ����ʵ��
 */
class UnitListPageDTO : public PageDTO<UnitListDTO::Wrapper> {
	DTO_INIT(UnitListPageDTO, PageDTO<UnitListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITLISTDTO_H_
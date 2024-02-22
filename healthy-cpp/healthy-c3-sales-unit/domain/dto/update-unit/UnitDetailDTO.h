#pragma once

#ifndef _UNITDETAILDTO_H_
#define _UNITDETAILDTO_H_

#include "../../GlobalInclude.h"
#include "TestDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* ǰ�ˡ���� ������󣺵�λ���� 
*/
class UnitDetailDTO : public oatpp::DTO
{
	DTO_INIT(UnitDetailDTO, DTO);

	// ������Ϣ
	//��λID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unit.field.id"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unit.field.name"));
	//�������
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unit.field.physical_type"));
	//ͳһ������ô���
	API_DTO_FIELD_DEFAULT(String, uscc, ZH_WORDS_GETTER("unit.field.uscc"));
	//��ҵ���ͱ���
	API_DTO_FIELD_DEFAULT(String, industryCode, ZH_WORDS_GETTER("unit.field.industry_code"));
	//��ҵ��������
	API_DTO_FIELD_DEFAULT(String, industryName, ZH_WORDS_GETTER("unit.field.industry_name"));
	//������������
	API_DTO_FIELD_DEFAULT(String, regionCode, ZH_WORDS_GETTER("unit.field.region_code"));
	//����������ַ
	API_DTO_FIELD_DEFAULT(String, regionName, ZH_WORDS_GETTER("unit.field.region_name"));
	//�������ͱ���
	API_DTO_FIELD_DEFAULT(String, economicTypeCode, ZH_WORDS_GETTER("unit.field.economic_type_code"));
	//������������
	API_DTO_FIELD_DEFAULT(String, economicTypeName, ZH_WORDS_GETTER("unit.field.economic_type_name"));
	//��λע���ַ
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("unit.field.address"));
	//��ҵ��ģ����
	API_DTO_FIELD_DEFAULT(String, businessScaleCode, ZH_WORDS_GETTER("unit.field.business_scale_code"));
	//��ҵ��ģ����
	API_DTO_FIELD_DEFAULT(String, businessScaleName, ZH_WORDS_GETTER("unit.field.business_scale_name"));
	//ְ������
	API_DTO_FIELD_DEFAULT(UInt32, employeesNum, ZH_WORDS_GETTER("unit.field.employees_num"));
	//�Ӵ�ְҵ��Σ����������
	API_DTO_FIELD_DEFAULT(UInt32, dangerNum, ZH_WORDS_GETTER("unit.field.danger_num"));
	//�����ϵ��
	API_DTO_FIELD_DEFAULT(String, linkMan2, ZH_WORDS_GETTER("unit.field.link_man2"));
	//�����ϵ�˵绰
	API_DTO_FIELD_DEFAULT(String, linkPhone2, ZH_WORDS_GETTER("unit.field.link_phone2"));
	//�����ļ����ƣ�Ӫҵִ�գ�
	API_DTO_FIELD_DEFAULT(String, attachment, ZH_WORDS_GETTER("unit.field.attachment"));

	// ������Ϣ
	//��������
	API_DTO_FIELD_DEFAULT(String, legalPerson, ZH_WORDS_GETTER("unit.field.legal_person"));
	//���˵绰
	API_DTO_FIELD_DEFAULT(String, legalPhone, ZH_WORDS_GETTER("unit.field.legal_phone"));
	//����������
	API_DTO_FIELD_DEFAULT(UInt32, workmanNum, ZH_WORDS_GETTER("unit.field.workman_num"));
	//�Ӵ�ְҵ��Σ������Ů������
	API_DTO_FIELD_DEFAULT(UInt32, workmistressNum, ZH_WORDS_GETTER("unit.field.workmistress_num"));
	//��λע���ʱ�
	API_DTO_FIELD_DEFAULT(String, postalCode, ZH_WORDS_GETTER("unit.field.postal_code"));
	//��Ӫ���
	API_DTO_FIELD_DEFAULT(String, workArea, ZH_WORDS_GETTER("unit.field.work_area"));
	//ע���ʽ�
	API_DTO_FIELD_DEFAULT(String, regCapital, ZH_WORDS_GETTER("unit.field.reg_capital"));
	//ְҵ������ȫ������
	API_DTO_FIELD_DEFAULT(String, safetyPrincipal, ZH_WORDS_GETTER("unit.field.safety_principal"));
	//��������
	API_DTO_FIELD_DEFAULT(String, filingDate, ZH_WORDS_GETTER("unit.field.filing_date"));
	//��������
	API_DTO_FIELD_DEFAULT(String, establishmentDate, ZH_WORDS_GETTER("unit.field.establishment_date"));
	//�����ϵ��
	API_DTO_FIELD_DEFAULT(String, linkMan1, ZH_WORDS_GETTER("unit.field.link_man1"));
	//�����ϵ�绰
	API_DTO_FIELD_DEFAULT(String, linkPhone1, ZH_WORDS_GETTER("unit.field.link_phone1"));
	//�����ϵ��ְ��
	API_DTO_FIELD_DEFAULT(String, position1, ZH_WORDS_GETTER("unit.field.position1"));
	//�����ϵ��ְ��
	API_DTO_FIELD_DEFAULT(String, position2, ZH_WORDS_GETTER("unit.field.position2"));
	//��ȫ��ϵ��ְ��
	API_DTO_FIELD_DEFAULT(String, safePosition, ZH_WORDS_GETTER("unit.field.safe_position"));
	//��ȫ��ϵ�˵绰
	API_DTO_FIELD_DEFAULT(String, safePhone, ZH_WORDS_GETTER("unit.field.safe_phone"));
	//������ϵ
	API_DTO_FIELD_DEFAULT(String, subjeConn, ZH_WORDS_GETTER("unit.field.subje_conn"));
	//��ҵ������ַ
	API_DTO_FIELD_DEFAULT(String, enrolAddress, ZH_WORDS_GETTER("unit.field.enrol_address"));
	//��ҵ�����ʱ�
	API_DTO_FIELD_DEFAULT(String, enrolPostalCode, ZH_WORDS_GETTER("unit.field.enrol_postal_code"));
	//ְҵ�����������
	API_DTO_FIELD_DEFAULT(String, occManaOffice, ZH_WORDS_GETTER("unit.field.occ_mana_office"));

	// �����Ϣ
	API_DTO_FIELD_DEFAULT(List<TestDetailDTO::Wrapper>, test, ZH_WORDS_GETTER("unit.field.test"));

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITDETAILDTO_H_
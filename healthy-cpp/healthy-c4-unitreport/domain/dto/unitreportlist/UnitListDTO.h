#pragma once

#ifndef _UNITLISTDTO_
#define _UNITLISTDTO_

#include "../../GlobalInclude.h"

/*
* ��쵥λ���������б����ݶ���ʵ��
*/

#include OATPP_CODEGEN_BEGIN(DTO)

class UnitListDTO : public oatpp::DTO
{
	//�����ʼ��
	DTO_INIT(UnitListDTO, DTO);
	//��λ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unitreport.unit.name"));
	//�������
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("unitreport.order.code"));
	//��������
	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("unitreport.order.signingTime"));
	//�Ƿ��ϱ�
	API_DTO_FIELD_DEFAULT(String, Escalation, "");
	//�������
	API_DTO_FIELD_DEFAULT(String, detectionType, "");
};

/*
* ��λ��ҳ�б�����ʵ��
*/
class UnitListPageDTO : public PageDTO<UnitListDTO::Wrapper>
{
	//�����ʼ��
	DTO_INIT(UnitListPageDTO, PageDTO<UnitListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif
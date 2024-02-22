#pragma once
#ifndef _CHECKLISTDTO_H_
#define _CHECKLISTDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* �����б�����ʵ��
* �����ˣ�Z
*/
class CheckReportListDTO : public oatpp::DTO
{
	DTO_INIT(CheckReportListDTO, DTO);
	// Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("report.field.id"));

	// ����
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("report.field.name"));

	// �Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("report.field.sex"));

	// ����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("report.field.age"));

	// �Ƿ����
	API_DTO_FIELD_DEFAULT(Boolean, statu, ZH_WORDS_GETTER("report.field.statu"));

	// �Ƿ��ӡ
	API_DTO_FIELD_DEFAULT(Boolean, print_state, ZH_WORDS_GETTER("report.field.printState"));

	// �Ƿ��������
	API_DTO_FIELD_DEFAULT(Boolean, sporadic_physical, ZH_WORDS_GETTER("report.field.sporadicPhysical"));

};
/*
	�����б��ҳʵ��
	������ Z
*/
class CheckReportListPageDTO : public PageDTO<CheckReportListDTO::Wrapper> {
	DTO_INIT(CheckReportListPageDTO, PageDTO<CheckReportListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CHECKLISTDTO_H_
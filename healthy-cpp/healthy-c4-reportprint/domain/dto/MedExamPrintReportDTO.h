#pragma once
#ifndef _MEDEXAMPRINTREPORTDTO_H_
#define _MEDEXAMPRINTREPORTDTO_H_
#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ�б����ݴ������ʵ��
 * �����ˣ�С��
 */
class MedExamPrintReportDTO : public oatpp::DTO
{
	DTO_INIT(MedExamPrintReportDTO, DTO);
	// Ψһ���
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("print.field.id"));
	// ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("print.field.name"));
	// ����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("print.field.age"));
	// �Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("print.field.sex"));
	// ���
	API_DTO_FIELD_DEFAULT(Boolean, statu, ZH_WORDS_GETTER("print.field.statu"));
	// ��ӡ
	API_DTO_FIELD_DEFAULT(Boolean,printState, ZH_WORDS_GETTER("print.field.printState"));
	// �������
	API_DTO_FIELD_DEFAULT(Boolean, sporadicPhysical, ZH_WORDS_GETTER("print.field.sporadicPhysical"));

};

/**
 * ��ҳ�������
 */
class MedExamPrintReportPageDTO : public PageDTO<MedExamPrintReportDTO::Wrapper>
{
	DTO_INIT(MedExamPrintReportPageDTO, PageDTO<MedExamPrintReportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEDEXAMPRINTREPORTDTO_H_
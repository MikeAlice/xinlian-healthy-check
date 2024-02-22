#pragma once
#ifndef _MEDEXAMPRINTREPORT_H_
#define _MEDEXAMPRINTREPORT_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����ӡ��ҳ��ѯ�����Ա
 * �����ˣ�С��
 */
class MedExamPrintReportQuery : public PageQuery
{
	DTO_INIT(MedExamPrintReportQuery, PageQuery);
	// �������
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("print.field.type"));
	// ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("print.field.name"));
	// �������
	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("print.field.orderId"));
	// �����
	API_DTO_FIELD_DEFAULT(String, testNum, ZH_WORDS_GETTER("print.field.testNum"));
	// ��λ����
	API_DTO_FIELD_DEFAULT(String, dept, ZH_WORDS_GETTER("print.field.dept"));
	// ��ʼ����
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("print.field.startDate"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("print.field.endDate"));
	// �Ƿ񸴲�
	API_DTO_FIELD_DEFAULT(Boolean, isRecheck, ZH_WORDS_GETTER("print.field.isRecheck"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEDEXAMPRINTR      EPORT_H_
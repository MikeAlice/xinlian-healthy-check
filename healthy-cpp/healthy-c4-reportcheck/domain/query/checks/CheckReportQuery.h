#pragma once
#ifndef _CHECKQUERY_H_
#define _CHECKQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/*
	���Ǳ�����˲�ѯ
	������ Z
*/
class CheckReportQuery : public PageQuery
{
	DTO_INIT(CheckReportQuery, PageQuery);
	// ��ѯ����
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("report.field.type"));

	// ����
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("report.field.name"));

	// �������
	API_DTO_FIELD_DEFAULT(String, order_id, ZH_WORDS_GETTER("report.field.orderId"));

	// �����
	API_DTO_FIELD_DEFAULT(String, test_num, ZH_WORDS_GETTER("report.field.testNum"));

	// ��λ����
	API_DTO_FIELD_DEFAULT(String, unit_id, ZH_WORDS_GETTER("report.field.unitId"));

	// �Ƿ����
	API_DTO_FIELD_DEFAULT(Boolean, statu, ZH_WORDS_GETTER("report.field.statu"));

	// �Ƿ񸴲�
	API_DTO_FIELD_DEFAULT(Boolean, is_recheck, ZH_WORDS_GETTER("report.field.isRecheck"));

	// ��ѯ��ʼ����
	API_DTO_FIELD_DEFAULT(String, stardate, ZH_WORDS_GETTER("report.field.starDate"));

	//��ѯ��������
	API_DTO_FIELD_DEFAULT(String, enddate, ZH_WORDS_GETTER("report.field.endDate"));

}; 

#include OATPP_CODEGEN_END(DTO)
#endif //!_CHECKQUERY_H_
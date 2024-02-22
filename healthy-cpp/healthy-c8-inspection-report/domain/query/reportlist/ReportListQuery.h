#pragma once

#ifndef _ReportList_QUERY_
#define _ReportList_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��챨���б��ѯ����
 */
class ReportListQuery : public PageQuery
{
	DTO_INIT(ReportListQuery, PageQuery);
	// �����
	DTO_FIELD(String, test_num);
	DTO_FIELD_INFO(test_num) {
		info->description = ZH_WORDS_GETTER("report-list.field.test_num");
	}
	// ��쵥λ
	DTO_FIELD(String, physical_unit);
	DTO_FIELD_INFO(physical_unit) {
		info->description = ZH_WORDS_GETTER("report-list.field.physical_unit");
	}
	// ���֤��
	DTO_FIELD(String, id_card);
	DTO_FIELD_INFO(id_card) {
		info->description = ZH_WORDS_GETTER("report-list.field.id_card");
	}

	// �������
	DTO_FIELD(String, check_date);
	DTO_FIELD_INFO(check_date) {
		info->description = ZH_WORDS_GETTER("report-list.field.check_date");
	}

	// ���״̬
	DTO_FIELD(Int32, statu);
	DTO_FIELD_INFO(statu) {
		info->description = ZH_WORDS_GETTER("report-list.field.statu");
	}

	// ����
	DTO_FIELD(String, person_name);
	DTO_FIELD_INFO(person_name) {
		info->description = ZH_WORDS_GETTER("report-list.field.person_name");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("report-list.field.sex");
	}
	// ����
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("report-list.field.age");
	}
	// �Ƿ�ϸ�
	DTO_FIELD(String, check_result);
	DTO_FIELD_INFO(check_result) {
		info->description = ZH_WORDS_GETTER("report-list.field.check_result");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif
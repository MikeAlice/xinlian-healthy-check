#pragma once

#ifndef _ReportList_DTO_
#define _ReportList_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б������
 */
class ReportListDTO : public oatpp::DTO
{
	DTO_INIT(ReportListDTO, DTO);

	// �����
	DTO_FIELD(String, test_num);
	DTO_FIELD_INFO(test_num) {
		info->description = ZH_WORDS_GETTER("reportlist.field.test_num");
	}
	// ���֤��
	DTO_FIELD(String, id_card);
	DTO_FIELD_INFO(id_card) {
		info->description = ZH_WORDS_GETTER("reportlist.field.id_card");
	}
	// ����
	DTO_FIELD(String, person_name);
	DTO_FIELD_INFO(person_name) {
		info->description = ZH_WORDS_GETTER("reportlist.field.person_name");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("reportlist.field.sex");
	}
	// ����
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("reportlist.field.age");
	}
	// �������
	DTO_FIELD(String, check_date);
	DTO_FIELD_INFO(check_date) {
		info->description = ZH_WORDS_GETTER("reportlist.field.check_date");
	}
	// �Ƿ�ϸ� ��Ҫѯ�ʣ�����
	DTO_FIELD(String, check_result);
	DTO_FIELD_INFO(check_result) {
		info->description = ZH_WORDS_GETTER("reportlist.field.check_result");
	}
	
	// ��쵥λ
	DTO_FIELD(String, physical_unit);
	DTO_FIELD_INFO(physical_unit) {
		info->description = ZH_WORDS_GETTER("reportlist.field.physical_unit");
	}

	// ���״̬
	DTO_FIELD(Int32, statu);
	DTO_FIELD_INFO(statu) {
		info->description = ZH_WORDS_GETTER("reportlist.field.statu");
	}
};

/**
 * �����б��ҳ�������
 */
class ReportListPageDTO : public PageDTO<ReportListDTO::Wrapper>
{
	DTO_INIT(ReportListPageDTO, PageDTO<ReportListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif
#pragma once
#ifndef _PERSONINFO_QUERY_
#define _PERSONINFO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PersoninfoQuery : public PageQuery
{
	DTO_INIT(PersoninfoQuery, PageQuery);
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("group_person.data.name");
	}
	// �����
	DTO_FIELD(String, test_num);
	DTO_FIELD_INFO(test_num) {
		info->description = ZH_WORDS_GETTER("group_person.data.test_num");
	}
	// �����Ա��������
	DTO_FIELD(String, dept);
	DTO_FIELD_INFO(dept) {
		info->description = ZH_WORDS_GETTER("group_person.data.dept");
	}
	// �������
	DTO_FIELD(String, physical_type);
	DTO_FIELD_INFO(physical_type) {
		info->description = ZH_WORDS_GETTER("group_person.data.physical_type");
	}
	// �Ƿ���
	DTO_FIELD(UInt64, is_check);
	DTO_FIELD_INFO(is_check) {
		info->description = ZH_WORDS_GETTER("group_person.data.is_check");
	}
	// �Ƿ񸴲�
	DTO_FIELD(UInt64, is_recheck);
	DTO_FIELD_INFO(is_recheck) {
		info->description = ZH_WORDS_GETTER("group_person.data.is_recheck");
	}
	// ��ʼ�Ǽ�ʱ��
	DTO_FIELD(String, start_regist_date);
	DTO_FIELD_INFO(start_regist_date) {
		info->description = ZH_WORDS_GETTER("group_person.data.start_regist_date");
	}
	// �����Ǽ�ʱ��
	DTO_FIELD(String, finish_regist_date);
	DTO_FIELD_INFO(finish_regist_date) {
		info->description = ZH_WORDS_GETTER("group_person.data.finish_regist_date");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSONINFO_QUERY_
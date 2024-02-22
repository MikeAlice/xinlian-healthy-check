#pragma once

#ifndef _HEALTH_CERTIFICATE_QUERY_
#define _HEALTH_CERTIFICATE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ�����Ŀ�б��ҳ��ѯ����
 */
class HealthCertificateListQuery : public PageQuery
{
	DTO_INIT(HealthCertificateListQuery, PageQuery);
	// ����֤���
	DTO_FIELD(String, health_ccertificate);
	DTO_FIELD_INFO(health_ccertificate) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.hcid");
	}
	// �Ǽ�ʱ�䷶Χ����ʼ��
	DTO_FIELD(String, start_date);
	DTO_FIELD_INFO(start_date) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.startDate");
	}
	// �Ǽ�ʱ�䷶Χ��������
	DTO_FIELD(String, end_date);
	DTO_FIELD_INFO(end_date) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.endDate");
	}
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.name");
	}
	// �ձ�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.sex");
	}
	// ����
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.age");
	}
	// ��ӡ״̬
	DTO_FIELD(Int32, print_state);
	DTO_FIELD_INFO(print_state) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.printState");
	}
	// �ϴ�״̬
	DTO_FIELD(Int32, is_upload);
	DTO_FIELD_INFO(is_upload) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.isUpload");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif
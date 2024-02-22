#pragma once

#ifndef _HEALTH_CERTIFICATE_DTO_
#define _HEALTH_CERTIFICATE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����֤�б������
 */
class HealthCertificateListDTO : public oatpp::DTO
{
	DTO_INIT(HealthCertificateListDTO, DTO);

	// ����֤����
	DTO_FIELD(String, health_ccertificate);
	DTO_FIELD_INFO(health_ccertificate) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.hcid");
	}

	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.name");
	}

	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.sex");
	}

	// ����
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.age");
	}

	// ��Ч����
	DTO_FIELD(String, term_of_validity);
	DTO_FIELD_INFO(term_of_validity) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.termOfValidity");
	}

	// ��֤��λ
	DTO_FIELD(String, unit_of_issue);
	DTO_FIELD_INFO(unit_of_issue) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.unitOfIssue");
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

/**
 * ����֤�б��ҳ�������
 */
class HealthCertificateListPageDTO : public PageDTO<HealthCertificateListDTO::Wrapper>
{
	DTO_INIT(HealthCertificateListPageDTO, PageDTO<HealthCertificateListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif
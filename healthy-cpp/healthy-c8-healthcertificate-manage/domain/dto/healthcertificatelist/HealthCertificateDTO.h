#pragma once

#ifndef _HEALTH_CERTIFICATE_DTO_
#define _HEALTH_CERTIFICATE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 健康证列表传输对象
 */
class HealthCertificateListDTO : public oatpp::DTO
{
	DTO_INIT(HealthCertificateListDTO, DTO);

	// 健康证编码
	DTO_FIELD(String, health_ccertificate);
	DTO_FIELD_INFO(health_ccertificate) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.hcid");
	}

	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.name");
	}

	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.sex");
	}

	// 年龄
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.age");
	}

	// 有效日期
	DTO_FIELD(String, term_of_validity);
	DTO_FIELD_INFO(term_of_validity) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.termOfValidity");
	}

	// 发证单位
	DTO_FIELD(String, unit_of_issue);
	DTO_FIELD_INFO(unit_of_issue) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.unitOfIssue");
	}

	// 打印状态
	DTO_FIELD(Int32, print_state);
	DTO_FIELD_INFO(print_state) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.printState");
	}

	// 上传状态
	DTO_FIELD(Int32, is_upload);
	DTO_FIELD_INFO(is_upload) {
		info->description = ZH_WORDS_GETTER("query-healthcertificatelist.field.isUpload");
	}
};

/**
 * 健康证列表分页传输对象
 */
class HealthCertificateListPageDTO : public PageDTO<HealthCertificateListDTO::Wrapper>
{
	DTO_INIT(HealthCertificateListPageDTO, PageDTO<HealthCertificateListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif
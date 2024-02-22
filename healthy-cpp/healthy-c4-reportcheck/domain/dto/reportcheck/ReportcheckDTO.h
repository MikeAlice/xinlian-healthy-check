#pragma once

#ifndef _REPORTCHECK_DTO_
#define _REPORTCHECK_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �������ر��洫����󡪡�ǧ��
 */
class ReportDownloadDTO : public oatpp::DTO
{
	DTO_INIT(ReportDownloadDTO, DTO);
	// ������
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	};
};

/**
 * ����״̬������󡪡�ǧ��
 */
class UpdateStatusDTO : public oatpp::DTO
{
	DTO_INIT(UpdateStatusDTO, DTO);
	// ������
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("reportcheck.field.id");
	}
	// ���״̬
	DTO_FIELD(UInt64, check_status);
	DTO_FIELD_INFO(check_status) {
		info->description = ZH_WORDS_GETTER("reportcheck.update.check_status");
	}
	// ��ӡ״̬
	DTO_FIELD(UInt64, print_status);
	DTO_FIELD_INFO(print_status) {
		info->description = ZH_WORDS_GETTER("reportcheck.update.print_status");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REPORTCHECK_DTO_
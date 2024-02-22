#pragma once

#ifndef _DOWNLOADSAMPLECODE_H_
#define _DOWNLOADSAMPLECODE_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ϣ�������ݶ���
 */
class DownloadSampleCodeDTO : public oatpp::DTO
{
	DTO_INIT(DownloadSampleCodeDTO, DTO);
	// src
	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("preview.field.report-url"), true, {});
	// ��������
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("preview.field.report-alt"));
	// ���ӵ�ַ
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("preview.field.href"));
public:
	DownloadSampleCodeDTO() {}
	DownloadSampleCodeDTO(String url, String alt = "", String href = "")
	{
		this->url = url;
		this->alt = alt;
		this->href = href;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DOWNLOADSAMPLECODE_H_
#pragma once

#ifndef _DOWNDTO_H_
#define _DOWNDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ÏÂÔØÄ£°æ
 */
class DownDTO : public oatpp::DTO
{
	DTO_INIT(DownDTO, DTO);

	// Í¼Æ¬src
	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("file.field.img-url"), true, {});
	// Í¼Æ¬ÎÄ×ÖÃèÊö
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("file.field.img-alt"));
	// Í¼Æ¬Á´½ÓµØÖ·
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("file.field.img-href"));
public:
	DownDTO() {}
	DownDTO(String url, String alt = "", String href = "")
	{
		this->url = url;
		this->alt = alt;
		this->href = href;
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_

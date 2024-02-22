#pragma once
#ifndef _PICDTO_H_
#define _PICDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class PicImageDTO : public oatpp::DTO
{
	DTO_INIT(PicImageDTO, DTO);
	// ͼƬsrc
	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("file.field.img-url"), true, {});
	// ͼƬ���ӵ�ַ
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("file.field.img-href"));
public:
	PicImageDTO() {}
	PicImageDTO(String url, String alt = "", String href = "") 
	{
		this->url = url;
		this->href = href;
	}
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEDTO_H_
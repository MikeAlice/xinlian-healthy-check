
#ifndef _IMAGEDTO_H_
#define _IMAGEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * editor图片信息传输数据对象
 */
class EditorImageDTO : public oatpp::DTO
{
	DTO_INIT(EditorImageDTO, DTO);
	// 图片src
	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("exalanding.file.field.img-url"), true, {});
	// 图片文字描述
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("exalanding.file.field.img-alt"));
	// 图片链接地址
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("exalanding.file.field.img-href"));
public:
	EditorImageDTO() {}
	EditorImageDTO(String url, String alt = "", String href = "") 
	{
		this->url = url;
		this->alt = alt;
		this->href = href;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IMAGEDTO_H_
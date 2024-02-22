#ifndef _FILEVO_H_
#define _FILEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Exalanding/FileDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * editor响应图片上传结果数据
 */
class EditorImageVO : public JsonVO<EditorImageDTO::Wrapper>
{
	DTO_INIT(EditorImageVO, JsonVO<EditorImageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEVO_H_
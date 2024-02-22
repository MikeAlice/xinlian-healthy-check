#pragma once

#ifndef _UPLOADMORE_VO_
#define _UPLOADMORE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/uploadmore/UploadMoreDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * UploadMoreJsonVO，用于响应给客户端的Json对象
 */
class UploadMoreJsonVO : public JsonVO<UploadMoreDTO::Wrapper> {
	DTO_INIT(UploadMoreJsonVO, JsonVO<UploadMoreDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 
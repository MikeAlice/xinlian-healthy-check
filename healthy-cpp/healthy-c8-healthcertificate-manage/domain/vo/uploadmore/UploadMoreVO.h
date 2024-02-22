#pragma once

#ifndef _UPLOADMORE_VO_
#define _UPLOADMORE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/uploadmore/UploadMoreDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * UploadMoreJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UploadMoreJsonVO : public JsonVO<UploadMoreDTO::Wrapper> {
	DTO_INIT(UploadMoreJsonVO, JsonVO<UploadMoreDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 
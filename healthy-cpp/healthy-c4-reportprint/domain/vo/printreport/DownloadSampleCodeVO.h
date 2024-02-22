#pragma once

#ifndef _DOWNLOADSAMPLECODEVO_H_
#define _DOWNLOADSAMPLECODEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/printreport/DownloadSampleCodeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * PDF上传结果数据
 */
class DownloadSampleCodeVO : public JsonVO<DownloadSampleCodeDTO::Wrapper>
{
	DTO_INIT(DownloadSampleCodeVO, JsonVO<DownloadSampleCodeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DOWNLOADSAMPLECODEVO_H_
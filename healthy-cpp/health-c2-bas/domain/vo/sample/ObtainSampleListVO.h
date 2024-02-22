#pragma once
#ifndef _OBTAINSAMPLELIST_VO_
#define _OBTAINSAMPLELIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/sample/ObtainSampleListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 列表显示JsonVO，用于响应给客户端的Json对象
 */
class ObtainSampleListJsonVO : public JsonVO<ObtainSampleListDTO::Wrapper> {
	DTO_INIT(ObtainSampleListJsonVO, JsonVO<ObtainSampleListDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class ObtainSampleListPageJsonVO : public JsonVO<ObtainSampleListPageDTO::Wrapper> {
	DTO_INIT(ObtainSampleListPageJsonVO, JsonVO<ObtainSampleListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OBTAINSAMPLELIST_VO_
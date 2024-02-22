#pragma once
#ifndef _PackageProNameListVO_
#define _PackageProNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/packagepronamelist/PackageProNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class PackageProNameListJsonVO : public JsonVO<PackageProNameListDTO::Wrapper> {
	DTO_INIT(PackageProNameListJsonVO, JsonVO<PackageProNameListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
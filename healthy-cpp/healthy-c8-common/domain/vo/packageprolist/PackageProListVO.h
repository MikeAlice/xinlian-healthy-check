#pragma once
#ifndef _PackageProListVO_
#define _PackageProListVO_

#include "../../GlobalInclude.h"
#include "../../dto/packageprolist/PackageProListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class PackageProListJsonVO : public JsonVO<PackageProListDTO::Wrapper> {
	DTO_INIT(PackageProListJsonVO, JsonVO<PackageProListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class PackageProListPageJsonVO : public JsonVO<PackageProListPageDTO::Wrapper> {
	DTO_INIT(PackageProListPageJsonVO, JsonVO<PackageProListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
#pragma once

#ifndef _UnitVO_H_
#define _UnitVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/getUserName/UnitListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表显示JsonVO实体
 */
class UnitListJsonVO : public JsonVO<UnitListDTO::Wrapper> {
	DTO_INIT(UnitListJsonVO, JsonVO<UnitListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class UnitListPageJsonVO : public JsonVO<UnitListPageDTO::Wrapper> {
	DTO_INIT(UnitListPageJsonVO, JsonVO<UnitListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
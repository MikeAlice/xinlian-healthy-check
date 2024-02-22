#pragma once
#ifndef _CHECKLISTVO_H_
#define _CHECKLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Exalanding/CheckListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 单位列表显示JsonVO实体
*/

class CheckListJsonVO : public JsonVO<CheckListDTO::Wrapper>
{
	DTO_INIT(CheckListJsonVO, JsonVO < CheckListDTO::Wrapper>);
};

/**
 * 定义一个体检人员名称列表分页显示JsonVO对象，用于响应给客户端
 */
class CheckListPageJsonVO : public JsonVO<CheckListPageDTO::Wrapper> {
	DTO_INIT(CheckListPageJsonVO, JsonVO<CheckListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CHECKLISTVO_H_

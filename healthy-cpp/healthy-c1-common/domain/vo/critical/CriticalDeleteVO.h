#pragma once
#ifndef _CRITICALDELETEVO_H_
#define _CRITICALDELETEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/critical/CriticalDeleteDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO,用来响应客户端Json对象
 */
class CriticalDeleteListJsonVO : public JsonVO<CriticalDeleteListDTO::Wrapper>
{
	DTO_INIT(CriticalDeleteListJsonVO, JsonVO<CriticalDeleteListDTO::Wrapper>);
public:
	//在构造函数中实例化data列表
	CriticalDeleteListJsonVO()
	{
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
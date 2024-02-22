#pragma once
#ifndef _CRITICALMODIFYVO_H_
#define _CRITICALMODIFYVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/critical/CriticalModifyDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO,用来响应客户端Json对象
 */
class CriticalModifyListJsonVO : public JsonVO<CriticalListDTO::Wrapper>
{
	DTO_INIT(CriticalModifyListJsonVO, JsonVO<CriticalListDTO::Wrapper>);
public:
	//在构造函数中实例化data列表
	CriticalModifyListJsonVO()
	{
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
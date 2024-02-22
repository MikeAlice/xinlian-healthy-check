#pragma once
#ifndef _CRITICALMODIFYVO_H_
#define _CRITICALMODIFYVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/critical/CriticalModifyDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO,������Ӧ�ͻ���Json����
 */
class CriticalModifyListJsonVO : public JsonVO<CriticalListDTO::Wrapper>
{
	DTO_INIT(CriticalModifyListJsonVO, JsonVO<CriticalListDTO::Wrapper>);
public:
	//�ڹ��캯����ʵ����data�б�
	CriticalModifyListJsonVO()
	{
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
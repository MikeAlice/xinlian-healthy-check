#pragma once
#ifndef _CRITICALDELETEVO_H_
#define _CRITICALDELETEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/critical/CriticalDeleteDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO,������Ӧ�ͻ���Json����
 */
class CriticalDeleteListJsonVO : public JsonVO<CriticalDeleteListDTO::Wrapper>
{
	DTO_INIT(CriticalDeleteListJsonVO, JsonVO<CriticalDeleteListDTO::Wrapper>);
public:
	//�ڹ��캯����ʵ����data�б�
	CriticalDeleteListJsonVO()
	{
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
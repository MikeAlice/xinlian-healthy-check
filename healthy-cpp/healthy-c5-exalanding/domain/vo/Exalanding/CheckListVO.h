#pragma once
#ifndef _CHECKLISTVO_H_
#define _CHECKLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Exalanding/CheckListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ��λ�б���ʾJsonVOʵ��
*/

class CheckListJsonVO : public JsonVO<CheckListDTO::Wrapper>
{
	DTO_INIT(CheckListJsonVO, JsonVO < CheckListDTO::Wrapper>);
};

/**
 * ����һ�������Ա�����б��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class CheckListPageJsonVO : public JsonVO<CheckListPageDTO::Wrapper> {
	DTO_INIT(CheckListPageJsonVO, JsonVO<CheckListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CHECKLISTVO_H_

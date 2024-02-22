#pragma once

#ifndef _UnitVO_H_
#define _UnitVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/getUserName/UnitListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ�б���ʾJsonVOʵ��
 */
class UnitListJsonVO : public JsonVO<UnitListDTO::Wrapper> {
	DTO_INIT(UnitListJsonVO, JsonVO<UnitListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UnitListPageJsonVO : public JsonVO<UnitListPageDTO::Wrapper> {
	DTO_INIT(UnitListPageJsonVO, JsonVO<UnitListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
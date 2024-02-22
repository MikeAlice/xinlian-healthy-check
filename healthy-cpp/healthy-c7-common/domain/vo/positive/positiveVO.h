#pragma once
#ifndef _POSITIVEVO_H_
#define _POSITIVEVO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "../../healthy-c7-common/domain/dto/positive/positiveListDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ���Խ���б���ʾJsonVOʵ��
 */
class PositiveListJsonVO : public JsonVO<PositiveListDTO::Wrapper> {
	DTO_INIT(PositiveListJsonVO, JsonVO<PositiveListDTO::Wrapper>);
};
/**
 * ���Խ���б���ʾ��ҳJsonVOʵ��
 */
class PositiveListPageJsonVO : public JsonVO<PositiveListPageDTO::Wrapper> {
	DTO_INIT(PositiveListPageJsonVO,JsonVO<PositiveListPageDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_POSITIVEVO_H_
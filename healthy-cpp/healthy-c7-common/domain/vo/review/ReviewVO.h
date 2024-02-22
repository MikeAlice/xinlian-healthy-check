#pragma once
#ifndef _REVIEWVO_H_
#define _REVIEWVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/review/ReviewListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  �����¼�б���ʾJsonVOʵ��
*/
class ReviewJsonVO : public JsonVO<ReviewListDTO::Wrapper> {
	DTO_INIT(ReviewJsonVO, JsonVO<ReviewListDTO::Wrapper>);
};

/**
 * �����¼�б���ʾ��ҳJsonVO
 */
class ReviewListPageJsonVO : public JsonVO<ReviewListPageDTO::Wrapper> {
	DTO_INIT(ReviewListPageJsonVO, JsonVO<ReviewListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REVIEWVO_H_
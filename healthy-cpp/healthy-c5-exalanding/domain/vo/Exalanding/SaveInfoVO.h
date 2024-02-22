#pragma once
#ifndef _SAVE_INFO_VO_H_
#define _SAVE_INFO_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Exalanding/SaveInfoDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class SaveInfoJsonVO : public JsonVO<SaveInfoDTO::Wrapper>
{
	DTO_INIT(SaveInfoJsonVO, JsonVO<SaveInfoDTO::Wrapper>);
};

/**
 * ����һ���û���Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class SaveInfoPageJsonVO : public JsonVO<SaveInfoPageDTO::Wrapper>
{
	DTO_INIT(SaveInfoPageJsonVO, JsonVO<SaveInfoPageDTO::Wrapper>);
};



#endif // _SAVE_INFO_VO_H_
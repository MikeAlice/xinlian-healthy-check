#pragma once
#ifndef _BASEINFO_VO_
#define _BASEINFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/contract/BaseInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BaseInfoJsonVO : public JsonVO<BaseInfoDTO::Wrapper> {
	DTO_INIT(BaseInfoJsonVO, JsonVO<BaseInfoDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BaseInfoPageJsonVO : public JsonVO<BaseInfoPageDTO::Wrapper> {
	DTO_INIT(BaseInfoPageJsonVO, JsonVO<BaseInfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
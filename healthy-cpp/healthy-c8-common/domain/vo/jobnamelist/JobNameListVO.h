#pragma once
#ifndef _JobNameListVO_
#define _JobNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/jobnamelist/JobNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class JobNameListJsonVO : public JsonVO<JobNameListDTO::Wrapper> {
	DTO_INIT(JobNameListJsonVO, JsonVO<JobNameListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class JobNameListPageJsonVO : public JsonVO<JobNameListPageDTO::Wrapper> {
	DTO_INIT(JobNameListPageJsonVO, JsonVO<JobNameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
#pragma once

#ifndef _VIEW_EXCEPTION_VO_
#define _VIEW_EXCEPTION_VO_

#include "../../GlobalInclude.h"
#include "../../dto/viewexception/ViewExceptionDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����֤�쳣JsonVO��������Ӧ���ͻ��˵�Json����
 */
class ViewExceptionJsonVO : public JsonVO<ViewExceptionDTO::Wrapper> {
	DTO_INIT(ViewExceptionJsonVO, JsonVO<ViewExceptionDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif
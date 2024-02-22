#pragma once
#ifndef _UserNameListVO_
#define _UserNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/usernamelist/UserNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UserNameListJsonVO : public JsonVO<UserNameListDTO::Wrapper> {
	DTO_INIT(UserNameListJsonVO, JsonVO<UserNameListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
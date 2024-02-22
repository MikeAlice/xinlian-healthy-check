#ifndef _ADDPACKVO_H_
#define _ADDPACKVO_H_


#include "../../GlobalInclude.h"
#include "../../dto/combo/AddPackDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class AddPackJsonVO : public JsonVO<AddPackDTO::Wrapper>
{
	DTO_INIT(AddPackJsonVO, JsonVO<AddPackDTO::Wrapper>);
};

/**
 * ����һ���û���Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class AddPackPageJsonVO : public JsonVO<AddPackPageDTO::Wrapper>
{
	DTO_INIT(AddPackPageJsonVO, JsonVO<AddPackPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDPACKVO_H_
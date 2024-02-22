#ifndef _DELPACKVO_H_
#define _DELPACKVO_H_


#include "../../GlobalInclude.h"
#include "../../dto/combo/DelPackDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class DelPackJsonVO : public JsonVO<DelPackDTO::Wrapper>
{
	DTO_INIT(DelPackJsonVO, JsonVO<DelPackDTO::Wrapper>);
};

/**
 * ����һ���û���Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class DelPackPageJsonVO : public JsonVO<DelPackPageDTO::Wrapper>
{
	DTO_INIT(DelPackPageJsonVO, JsonVO<DelPackPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DELPACKVO_H_
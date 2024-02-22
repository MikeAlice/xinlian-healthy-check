#ifndef _UPDATEPACKVO_H_
#define _UPDATEPACKVO_H_


#include "../../GlobalInclude.h"
#include "../../dto/combo/UpdatePackDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class UpdatePackJsonVO : public JsonVO<UpdatePackDTO::Wrapper>
{
	DTO_INIT(UpdatePackJsonVO, JsonVO<UpdatePackDTO::Wrapper>);
};

/**
 * ����һ���û���Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class UpdatePackPageJsonVO : public JsonVO<UpdatePackPageDTO::Wrapper>
{
	DTO_INIT(UpdatePackPageJsonVO, JsonVO<UpdatePackPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UPDATEPACKVO_H_
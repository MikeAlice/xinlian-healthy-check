#ifndef _RESRULELIST_VO_
#define _RESRULELIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/positive/resRuleListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������б�JsonVOʵ��
 */
class resRuleListJsonVO : public JsonVO<resRuleListDTO::Wrapper>
{
	DTO_INIT(resRuleListJsonVO, JsonVO<resRuleListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RESRULELIST_VO_
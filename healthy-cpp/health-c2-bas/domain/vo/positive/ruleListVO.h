#ifndef _ruleList_VO_
#define _ruleList_VO_

#include "../../GlobalInclude.h"
#include "../../dto/positive/ruleListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 规则列表JsonVO实体
 */
class ruleJsonVO : public JsonVO<ruleListDTO::Wrapper>
{
	DTO_INIT(ruleJsonVO, JsonVO<ruleListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_rule_VO_
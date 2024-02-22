#ifndef __DEATIL_VO__
#define __DEATIL_VO__

#include "../../GlobalInclude.h"
#include "../../dto/positive/DeatilDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 阳性结果显示JsonVO，用于响应给客户端的Json对象
 */
class DeatilJsonVO : public JsonVO<DeatilDTO::Wrapper> {
	DTO_INIT(DeatilJsonVO, JsonVO<DeatilDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !__DEATIL_VO__
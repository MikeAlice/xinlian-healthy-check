#ifndef __DEATIL_VO__
#define __DEATIL_VO__

#include "../../GlobalInclude.h"
#include "../../dto/positive/DeatilDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���Խ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DeatilJsonVO : public JsonVO<DeatilDTO::Wrapper> {
	DTO_INIT(DeatilJsonVO, JsonVO<DeatilDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !__DEATIL_VO__
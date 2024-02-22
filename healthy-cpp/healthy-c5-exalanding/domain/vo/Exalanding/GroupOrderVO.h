#ifndef _GROUP_ORDER_LIST_JSONVO_
#define _GROUP_ORDER_LIST_JSONVO_

#include "../../GlobalInclude.h"
#include "../../dto/Exalanding/GroupOrderListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GroupOrderListJsonVO :public JsonVO<GroupOrderListDTO::Wrapper>
{
	DTO_INIT(GroupOrderListJsonVO, JsonVO<GroupOrderListDTO::Wrapper>);
};


/**
 * 定义一个体检人员名称列表分页显示JsonVO对象，用于响应给客户端
 */
class GroupOrderListPageJsonVO : public JsonVO<GroupOrderListPageDTO::Wrapper> {
	DTO_INIT(GroupOrderListPageJsonVO, JsonVO<GroupOrderListPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_ORDER_LIST_JSONVO_
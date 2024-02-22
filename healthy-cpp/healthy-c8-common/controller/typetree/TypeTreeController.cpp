#include "TypeTreeController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
TypeTreeJsonVO::Wrapper TypeTreeController::execQueryTypeTree(const PayloadDTO& payload)
{
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, TypeTreeApiClient, "query-typetree-api");
	// 构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 返回查询结果
	return ac->queryTypeTree(token)->readBodyToDto<TypeTreeJsonVO::Wrapper>(om);
}

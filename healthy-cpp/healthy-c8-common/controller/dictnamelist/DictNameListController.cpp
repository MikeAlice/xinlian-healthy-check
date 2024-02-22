#include "DictNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
DictNameListJsonVO::Wrapper DictNameListController::execQueryDictNameList(const PayloadDTO& payload)
{
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, DictNameListApiClient, "dictionary-list-api");
	// 构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 返回查询结果
	return ac->queryDictNameList(token)->readBodyToDto<DictNameListJsonVO::Wrapper>(om);
}

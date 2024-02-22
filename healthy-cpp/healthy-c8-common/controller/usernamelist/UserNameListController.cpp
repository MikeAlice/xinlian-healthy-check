#include "UserNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
UserNameListJsonVO::Wrapper UserNameListController::execQueryUserNameList(const PayloadDTO& payload)
{
	//构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	//创建客户端对象
	API_CLIENT_CREATE(ac, om, UserNameListApiClient, "query-usernamelist-api");
	//返回结果
	return ac->queryUserNameList(token)->readBodyToDto<UserNameListJsonVO::Wrapper>(om);
}

#include "UserNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
UserNameListJsonVO::Wrapper UserNameListController::execQueryUserNameList(const PayloadDTO& payload)
{
	//����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	//�����ͻ��˶���
	API_CLIENT_CREATE(ac, om, UserNameListApiClient, "query-usernamelist-api");
	//���ؽ��
	return ac->queryUserNameList(token)->readBodyToDto<UserNameListJsonVO::Wrapper>(om);
}

#include "DictNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
DictNameListJsonVO::Wrapper DictNameListController::execQueryDictNameList(const PayloadDTO& payload)
{
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, DictNameListApiClient, "dictionary-list-api");
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// ���ز�ѯ���
	return ac->queryDictNameList(token)->readBodyToDto<DictNameListJsonVO::Wrapper>(om);
}

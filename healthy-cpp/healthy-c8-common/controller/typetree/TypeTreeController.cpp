#include "TypeTreeController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
TypeTreeJsonVO::Wrapper TypeTreeController::execQueryTypeTree(const PayloadDTO& payload)
{
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, TypeTreeApiClient, "query-typetree-api");
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// ���ز�ѯ���
	return ac->queryTypeTree(token)->readBodyToDto<TypeTreeJsonVO::Wrapper>(om);
}

#include "SectionNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"

SectionNameListJsonVO::Wrapper SectionNameListController::execQuerySectionNameList(const PayloadDTO& payload)
{
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, SectionNameListApiClient, "query-sectionnamelist-api");
	// ���ؽ��
	return ac->querySectionNameList(token)->readBodyToDto<SectionNameListJsonVO::Wrapper>(om);
}

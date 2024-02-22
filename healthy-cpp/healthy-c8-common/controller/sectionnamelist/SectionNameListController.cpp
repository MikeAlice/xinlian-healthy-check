#include "SectionNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"

SectionNameListJsonVO::Wrapper SectionNameListController::execQuerySectionNameList(const PayloadDTO& payload)
{
	// 构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, SectionNameListApiClient, "query-sectionnamelist-api");
	// 返回结果
	return ac->querySectionNameList(token)->readBodyToDto<SectionNameListJsonVO::Wrapper>(om);
}

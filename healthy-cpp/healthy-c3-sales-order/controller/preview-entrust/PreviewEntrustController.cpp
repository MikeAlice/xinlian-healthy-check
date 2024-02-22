#include "stdafx.h"
#include "PreviewEntrustController.h"
#include "../../service/preview-entrust/PreviewEntrustService.h"

StringJsonVO::Wrapper PreviewEntrustController::execPreviewEntrust(const String& orderId)
{
	PreviewEntrustService service;
	std::string url=service.getInfo(orderId.getValue(""));
	
	//返回文件路径
	auto jvo = StringJsonVO::createShared();
	if (!url.empty())
		jvo->success(url);
	else
		jvo->fail("fail to get entrust");
	return jvo;
}
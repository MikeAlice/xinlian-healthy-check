#pragma once

#ifndef _UPLOADENTRUSTCONTROLLER_H_
#define _UPLOADENTRUSTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 保存附件    负责人：y
 */
class UploadEntrustController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(UploadEntrustController);
public: // 3 定义接口
// 	// 3.1 定义接口描述
// 	// 3.2 定义接口处理
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("order.upload-entrust.summary"), uploadEntrust, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT(API_M_POST, "sales/order/upload-entrust", uploadEntrust, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadEntrust(request));

private: // 3.3 定义接口执行函数
	StringJsonVO::Wrapper execUploadEntrust(std::shared_ptr<IncomingRequest> request);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_UPLOADENTRUSTCONTROLLER_H_

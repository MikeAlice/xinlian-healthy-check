#pragma once

#ifndef _IMPORTPERSONCONTROLLER_H_
#define _IMPORTPERSONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 保存导入信息    负责人：Gary
 */
class ImportPersonController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ImportPersonController);
public: // 3 定义接口
// 	// 3.1 定义接口描述
// 	// 3.2 定义接口处理
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("order.import-person.summary"), importPerson, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT(API_M_POST, "sales/order/import-person", importPerson, REQUEST(std::shared_ptr<IncomingRequest>, request), execImportPerson(request));

private: // 3.3 定义接口执行函数
	StringJsonVO::Wrapper execImportPerson(std::shared_ptr<IncomingRequest> request);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_IMPORTPERSONCONTROLLER_H_

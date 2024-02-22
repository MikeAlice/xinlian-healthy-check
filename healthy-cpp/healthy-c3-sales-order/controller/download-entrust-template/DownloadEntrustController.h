#pragma once

#ifndef _DOWNLOADENTRUSTCONTROLLER_H_
#define _DOWNLOADENTRUSTCONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "../../../lib-oatpp/include/oatpp/web/server/api/ApiController.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * 下载委托合同模板    负责人：星星果
 */

class DownloadEntrustController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(DownloadEntrustController);
public:
	ENDPOINT_INFO(downloadEntrust) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.download-entrust.summary"), Void);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("order.field.id"), "1", true);
	}
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sales/order/download-entrust/{id}", downloadEntrust, PATH(String, id), execDownloadEntrust(id));
	ENDPOINT(API_M_GET, "/sales/order/download-entrust/{id}", downloadEntrust, PATH(String, id), API_HANDLER_AUTH_PARAME) {
		return execDownloadEntrust(id);
	}
private:
	// 查询所有
	std::shared_ptr<OutgoingResponse> execDownloadEntrust(const String& id);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_DOWNLOADENTRUSTCONTROLLER_H_

#pragma once

#ifndef _DOWNLOADPERSONCONTROLLER_H_
#define _DOWNLOADPERSONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "../../../lib-oatpp/include/oatpp/web/server/api/ApiController.hpp"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 生成导入模板    负责人：Gary
 */
class DownloadPersonController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DownloadPersonController);
public: // 3 定义接口
// 	// 3.1 定义接口描述
// 	// 3.2 定义接口处理
	ENDPOINT_INFO(downloadPerson) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.download-person.summary"), Void);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("order.field.id"), "1", true);
	}
	ENDPOINT(API_M_GET, "/sales/order/download-person/{id}", downloadPerson, PATH(String, id), API_HANDLER_AUTH_PARAME) {
		return execDownloadPerson(id);
	}

private: // 3.3 定义接口执行函数
	std::shared_ptr<OutgoingResponse> execDownloadPerson(const String& id);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_DOWNLOADPERSONCONTROLLER_H_

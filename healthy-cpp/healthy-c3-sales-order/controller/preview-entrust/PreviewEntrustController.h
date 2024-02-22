#pragma once

#ifndef _PREVIEWENTRUSTCONTROLLER_H_
#define _PREVIEWENTRUSTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
//#include "../../domain/query/preview-entrust/PreviewEntrustQuery.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 附件(委托合同)预览    负责人：kzz
 */
class PreviewEntrustController: public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PreviewEntrustController);
public: // 3 定义接口
// 	// 3.1 定义接口描述
// 	// 3.2 定义接口处理
	ENDPOINT_INFO(previewEntrust) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.preview-entrust.summary"), StringJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "orderId", ZH_WORDS_GETTER("order.field.id"), "", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sales/order/preview-entrust/{orderId}", previewEntrust, PATH(String, orderId), execPreviewEntrust(orderId));
private: // 3.3 定义接口执行函数
	StringJsonVO::Wrapper execPreviewEntrust(const String& orderId);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_PREVIEWENTRUSTCONTROLLER_H_

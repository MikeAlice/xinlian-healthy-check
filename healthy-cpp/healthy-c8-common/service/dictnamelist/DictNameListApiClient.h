#pragma once
#ifndef _DictNameListAPICLIENT_H_
#define _DictNameListAPICLIENT_H_

//1 导入必须头文件
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * 获取工种名称列表ApiClient定义声明式服务
 */
class DictNameListApiClient : public oatpp::web::client::ApiClient //2.继承这个类
{
	// 3 定义ApiClient控制器使用宏---开始
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 初始化定义
	API_CLIENT_INIT(DictNameListApiClient);

	// 5 使用API_CALL或API_CALL_ASYNC声明调用服务接口

	API_CALL(API_M_GET, "/common/query-dictionary-list", queryDictNameList, API_HANDLER_AUTN_HEADER);
};

#include OATPP_CODEGEN_END(ApiClient);
//3 取消ApiClient控制器使用宏-- - 结束

#endif // !_DictNameListAPICLIENT_H_
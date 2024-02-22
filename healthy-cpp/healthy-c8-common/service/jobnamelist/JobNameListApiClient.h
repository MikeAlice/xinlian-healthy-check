#pragma once
#ifndef _JobNameListApiClient_H_
#define _JobNameListApiClient_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"


#include OATPP_CODEGEN_BEGIN(ApiClient)
/**
 * 获取组合项目列表ApiClient定义声明式服务
 */
class JobNameListApiClient : public oatpp::web::client::ApiClient // 2 继承这个类
{
	//  初始化定义
	API_CLIENT_INIT(JobNameListApiClient);
	// 通过ID查询
	API_CALL(API_M_GET, "now-dev-null", queryJobNameList, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, keyword));
};

#include OATPP_CODEGEN_END(ApiClient)
#endif

#pragma once
#ifndef _TermNameListApiClient_H_
#define _TermNameListApiClient_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"


#include OATPP_CODEGEN_BEGIN(ApiClient)
/**
 * 获取组合项目列表ApiClient定义声明式服务
 */
class TermNameListApiClient : public oatpp::web::client::ApiClient // 2 继承这个类
{

	//  初始化定义
	API_CLIENT_INIT(TermNameListApiClient);

	// 通过ID查询
	API_CALL(API_M_GET, "now-dev-null", queryTermNameList, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, 
			 QUERY(String, type_inspection), QUERY(String, type_term), QUERY(String, factor_danger), QUERY(String, statu_on),
			 QUERY(String, content_term), QUERY(String, create_date));
};

#include OATPP_CODEGEN_END(ApiClient)
#endif

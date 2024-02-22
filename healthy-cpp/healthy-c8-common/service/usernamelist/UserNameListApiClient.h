#pragma once
#ifndef  _UserNameListApiClient_H_
#define _UserNameListApiClient_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"


#include OATPP_CODEGEN_BEGIN(ApiClient)

class UserNameListApiClient : public oatpp::web::client::ApiClient {
	//初始化定义
	API_CLIENT_INIT(UserNameListApiClient);
	//声明式调用服务接口
	API_CALL(API_M_GET, "now-dev-null", queryUserNameList, API_HANDLER_AUTN_HEADER);
};

#include OATPP_CODEGEN_END(ApiClient);

#endif // !_UserNameListApiClient_H_

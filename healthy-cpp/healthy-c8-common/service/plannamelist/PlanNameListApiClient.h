#pragma once
#ifndef _PlanNameListApiClient_H_
#define _PlanNameListApiClient_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiClient)

class PlanNameListApiClient : public oatpp::web::client::ApiClient
{
	// ��ʼ������
	API_CLIENT_INIT(PlanNameListApiClient);
	// ����ʽ���÷���ӿ�
	API_CALL(API_M_GET, "now-dev-null", queryPlanNameList, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String,keyword));
};

#include OATPP_CODEGEN_END(ApiClient)

#endif // !_AREAAPICONTROLLER_H_
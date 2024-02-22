#pragma once
#ifndef _SectionNameListApiClient_H_
#define _SectionNameListApiClient_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiClient)

class SectionNameListApiClient : public oatpp::web::client::ApiClient
{
	// ��ʼ������
	API_CLIENT_INIT(SectionNameListApiClient);
	// ����ʽ���÷���ӿ�
	API_CALL(API_M_GET, "now-dev-null", querySectionNameList, API_HANDLER_AUTN_HEADER);
};

#include OATPP_CODEGEN_END(ApiClient)

#endif // !_AREAAPICONTROLLER_H_
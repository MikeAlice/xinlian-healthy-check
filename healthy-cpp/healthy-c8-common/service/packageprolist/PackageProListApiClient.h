#pragma once
#ifndef _PackageProListApiClient_H_
#define _PackageProListApiClient_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"


#include OATPP_CODEGEN_BEGIN(ApiClient)
/**
 * ��ȡ�����Ŀ�б�ApiClient��������ʽ����
 */
class PackageProListApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{

	//  ��ʼ������
	API_CLIENT_INIT(PackageProListApiClient);

	// ͨ��ID��ѯ
	API_CALL(API_M_GET, "now-dev-null", queryPackageProList, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, keyword), QUERY(String, section));
};

#include OATPP_CODEGEN_END(ApiClient)
#endif

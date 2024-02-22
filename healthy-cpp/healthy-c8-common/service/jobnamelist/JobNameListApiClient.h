#pragma once
#ifndef _JobNameListApiClient_H_
#define _JobNameListApiClient_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"


#include OATPP_CODEGEN_BEGIN(ApiClient)
/**
 * ��ȡ�����Ŀ�б�ApiClient��������ʽ����
 */
class JobNameListApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{
	//  ��ʼ������
	API_CLIENT_INIT(JobNameListApiClient);
	// ͨ��ID��ѯ
	API_CALL(API_M_GET, "now-dev-null", queryJobNameList, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, keyword));
};

#include OATPP_CODEGEN_END(ApiClient)
#endif

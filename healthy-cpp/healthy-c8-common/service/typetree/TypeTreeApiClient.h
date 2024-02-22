#pragma once
#ifndef _TypeTreeApiClient_H_
#define _TypeTreeApiClient_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"


#include OATPP_CODEGEN_BEGIN(ApiClient)
/**
 * ��ȡ�����Ŀ�б�ApiClient��������ʽ����
 */
class TypeTreeApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{

	//  ��ʼ������
	API_CLIENT_INIT(TypeTreeApiClient);

	// ͨ��ID��ѯ
	API_CALL(API_M_GET, "now-dev-null", queryTypeTree, API_HANDLER_AUTN_HEADER);
};

#include OATPP_CODEGEN_END(ApiClient)
#endif

#pragma once
#ifndef _TermNameListApiClient_H_
#define _TermNameListApiClient_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"


#include OATPP_CODEGEN_BEGIN(ApiClient)
/**
 * ��ȡ�����Ŀ�б�ApiClient��������ʽ����
 */
class TermNameListApiClient : public oatpp::web::client::ApiClient // 2 �̳������
{

	//  ��ʼ������
	API_CLIENT_INIT(TermNameListApiClient);

	// ͨ��ID��ѯ
	API_CALL(API_M_GET, "now-dev-null", queryTermNameList, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, 
			 QUERY(String, type_inspection), QUERY(String, type_term), QUERY(String, factor_danger), QUERY(String, statu_on),
			 QUERY(String, content_term), QUERY(String, create_date));
};

#include OATPP_CODEGEN_END(ApiClient)
#endif

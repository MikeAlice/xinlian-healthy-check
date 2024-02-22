#pragma once
 
#ifndef _PRINTREPORTAPICLIENT_H_
#define _PRINTREPORTAPICLIENT_H_


#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"


class PrintReportApiClient : public oatpp::web::client::ApiClient 
{

#include OATPP_CODEGEN_BEGIN(ApiClient)
	

	API_CLIENT_INIT(PrintReportApiClient);

	// Í¨¹ýID²éÑ¯
	API_CALL(API_M_GET, "/query-one", queryById, API_HANDLER_AUTN_HEADER, QUERY(String, id));
	
#include OATPP_CODEGEN_END(ApiClient)
	
};

#endif // !_PRINTREPORTAPICLIENT_H_
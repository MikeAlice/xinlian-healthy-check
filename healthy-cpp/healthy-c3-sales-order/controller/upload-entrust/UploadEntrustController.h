#pragma once

#ifndef _UPLOADENTRUSTCONTROLLER_H_
#define _UPLOADENTRUSTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���渽��    �����ˣ�y
 */
class UploadEntrustController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(UploadEntrustController);
public: // 3 ����ӿ�
// 	// 3.1 ����ӿ�����
// 	// 3.2 ����ӿڴ���
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("order.upload-entrust.summary"), uploadEntrust, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT(API_M_POST, "sales/order/upload-entrust", uploadEntrust, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadEntrust(request));

private: // 3.3 ����ӿ�ִ�к���
	StringJsonVO::Wrapper execUploadEntrust(std::shared_ptr<IncomingRequest> request);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_UPLOADENTRUSTCONTROLLER_H_

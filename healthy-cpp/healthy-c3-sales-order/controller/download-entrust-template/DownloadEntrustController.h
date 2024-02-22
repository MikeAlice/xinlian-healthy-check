#pragma once

#ifndef _DOWNLOADENTRUSTCONTROLLER_H_
#define _DOWNLOADENTRUSTCONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "../../../lib-oatpp/include/oatpp/web/server/api/ApiController.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * ����ί�к�ͬģ��    �����ˣ����ǹ�
 */

class DownloadEntrustController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(DownloadEntrustController);
public:
	ENDPOINT_INFO(downloadEntrust) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.download-entrust.summary"), Void);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("order.field.id"), "1", true);
	}
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sales/order/download-entrust/{id}", downloadEntrust, PATH(String, id), execDownloadEntrust(id));
	ENDPOINT(API_M_GET, "/sales/order/download-entrust/{id}", downloadEntrust, PATH(String, id), API_HANDLER_AUTH_PARAME) {
		return execDownloadEntrust(id);
	}
private:
	// ��ѯ����
	std::shared_ptr<OutgoingResponse> execDownloadEntrust(const String& id);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_DOWNLOADENTRUSTCONTROLLER_H_

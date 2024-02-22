#pragma once

#ifndef _DOWNLOADPERSONCONTROLLER_H_
#define _DOWNLOADPERSONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "../../../lib-oatpp/include/oatpp/web/server/api/ApiController.hpp"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���ɵ���ģ��    �����ˣ�Gary
 */
class DownloadPersonController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DownloadPersonController);
public: // 3 ����ӿ�
// 	// 3.1 ����ӿ�����
// 	// 3.2 ����ӿڴ���
	ENDPOINT_INFO(downloadPerson) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.download-person.summary"), Void);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("order.field.id"), "1", true);
	}
	ENDPOINT(API_M_GET, "/sales/order/download-person/{id}", downloadPerson, PATH(String, id), API_HANDLER_AUTH_PARAME) {
		return execDownloadPerson(id);
	}

private: // 3.3 ����ӿ�ִ�к���
	std::shared_ptr<OutgoingResponse> execDownloadPerson(const String& id);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_DOWNLOADPERSONCONTROLLER_H_

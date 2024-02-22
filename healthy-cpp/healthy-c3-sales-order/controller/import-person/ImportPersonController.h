#pragma once

#ifndef _IMPORTPERSONCONTROLLER_H_
#define _IMPORTPERSONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���浼����Ϣ    �����ˣ�Gary
 */
class ImportPersonController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ImportPersonController);
public: // 3 ����ӿ�
// 	// 3.1 ����ӿ�����
// 	// 3.2 ����ӿڴ���
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("order.import-person.summary"), importPerson, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT(API_M_POST, "sales/order/import-person", importPerson, REQUEST(std::shared_ptr<IncomingRequest>, request), execImportPerson(request));

private: // 3.3 ����ӿ�ִ�к���
	StringJsonVO::Wrapper execImportPerson(std::shared_ptr<IncomingRequest> request);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_IMPORTPERSONCONTROLLER_H_

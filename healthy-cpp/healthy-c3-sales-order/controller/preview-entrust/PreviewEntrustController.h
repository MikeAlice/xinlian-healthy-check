#pragma once

#ifndef _PREVIEWENTRUSTCONTROLLER_H_
#define _PREVIEWENTRUSTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
//#include "../../domain/query/preview-entrust/PreviewEntrustQuery.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ����(ί�к�ͬ)Ԥ��    �����ˣ�kzz
 */
class PreviewEntrustController: public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PreviewEntrustController);
public: // 3 ����ӿ�
// 	// 3.1 ����ӿ�����
// 	// 3.2 ����ӿڴ���
	ENDPOINT_INFO(previewEntrust) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.preview-entrust.summary"), StringJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(String, "orderId", ZH_WORDS_GETTER("order.field.id"), "", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sales/order/preview-entrust/{orderId}", previewEntrust, PATH(String, orderId), execPreviewEntrust(orderId));
private: // 3.3 ����ӿ�ִ�к���
	StringJsonVO::Wrapper execPreviewEntrust(const String& orderId);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_PREVIEWENTRUSTCONTROLLER_H_

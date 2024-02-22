#ifndef _SAMPLEBARCODESVIEW_CONTROLLER_
#define _SAMPLEBARCODESVIEW_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include"ApiHelper.h"
#include"domain/query/samplebarcodesview/SampleBarcodesViewQuery.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
*��ѯ��������
*/
class SampleBarcodesViewController :public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(SampleBarcodesViewController);
	// 3 ����ӿ�
public:
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/resultentry/barcod", querySampleBarcodesView, BODY_DTO(SampleBarcodesViewQuery::Wrapper,qdto), execQuerySampleBarcodesView(qdto,authObject->getPayload()));
	ENDPOINT_INFO(querySampleBarcodesView) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("samplebarcodesview.get.barcode"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
private:
	StringJsonVO::Wrapper execQuerySampleBarcodesView(const SampleBarcodesViewQuery::Wrapper& qdto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_SAMPLEBARCODESVIEW_CONTROLLER_


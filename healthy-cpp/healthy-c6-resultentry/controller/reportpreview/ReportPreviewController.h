#ifndef _REPORTPREVIEW_CONTROLLER_
#define _REPORTPREVIEW_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include"ApiHelper.h"
#include"domain/query/reportpreview/ReportPreviewQuery.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
*����Ԥ��
*/
class ReportPreviewController :public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ReportPreviewController);
	// 3 ����ӿ�
public:
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/resultentry/report", queryReportPreview, BODY_DTO(ReportPreviewQuery::Wrapper, qdto), execQueryReportPreview(qdto, authObject->getPayload()));
	ENDPOINT_INFO(queryReportPreview) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("reportpreview.get.report"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
private:
	StringJsonVO::Wrapper execQueryReportPreview(const ReportPreviewQuery::Wrapper& qdto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_REPORTPREVIEW_CONTROLLER_


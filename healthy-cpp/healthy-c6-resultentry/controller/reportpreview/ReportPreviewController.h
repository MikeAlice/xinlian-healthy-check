#ifndef _REPORTPREVIEW_CONTROLLER_
#define _REPORTPREVIEW_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include"ApiHelper.h"
#include"domain/query/reportpreview/ReportPreviewQuery.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
*报告预览
*/
class ReportPreviewController :public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ReportPreviewController);
	// 3 定义接口
public:
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/resultentry/report", queryReportPreview, BODY_DTO(ReportPreviewQuery::Wrapper, qdto), execQueryReportPreview(qdto, authObject->getPayload()));
	ENDPOINT_INFO(queryReportPreview) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("reportpreview.get.report"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
private:
	StringJsonVO::Wrapper execQueryReportPreview(const ReportPreviewQuery::Wrapper& qdto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_REPORTPREVIEW_CONTROLLER_


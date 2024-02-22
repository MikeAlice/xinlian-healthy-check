#ifndef _SAMPLEBARCODESVIEW_CONTROLLER_
#define _SAMPLEBARCODESVIEW_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include"ApiHelper.h"
#include"domain/query/samplebarcodesview/SampleBarcodesViewQuery.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
*查询样本条码
*/
class SampleBarcodesViewController :public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(SampleBarcodesViewController);
	// 3 定义接口
public:
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/resultentry/barcod", querySampleBarcodesView, BODY_DTO(SampleBarcodesViewQuery::Wrapper,qdto), execQuerySampleBarcodesView(qdto,authObject->getPayload()));
	ENDPOINT_INFO(querySampleBarcodesView) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("samplebarcodesview.get.barcode"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
private:
	StringJsonVO::Wrapper execQuerySampleBarcodesView(const SampleBarcodesViewQuery::Wrapper& qdto, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_SAMPLEBARCODESVIEW_CONTROLLER_


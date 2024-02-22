#pragma once
#ifndef _ReportReviewController_
#define _ReportReviewController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/reportreview/ReportReviewDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class ReportReviewController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ReportReviewController);
	// 3 定义接口
public:
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("reportreview.put.summary"), modifyReportReview, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/inspection-report/modify-reportreview", modifyReportReview, BODY_DTO(List<ReportReviewDTO::Wrapper>, dtoArray), execModifyReportReview(dtoArray));
private:
	// 3.3 演示修改数据
	StringJsonVO::Wrapper execModifyReportReview(const List<ReportReviewDTO::Wrapper>& dtoArray);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
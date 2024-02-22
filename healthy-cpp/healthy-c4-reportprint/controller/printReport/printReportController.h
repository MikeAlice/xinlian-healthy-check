#pragma once

#ifndef _PRINTREPORT_CONTROLLER_H_
#define _PRINTREPORT_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/printreport/PrintReportQuery.h"
#include "domain/dto/printreport/PrintReportDTO.h"
#include "domain/vo/printreport/PrintReportVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
 * 打印PDF报告
 */
class PrintReportController : public oatpp::web::server::api::ApiController // 1 
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(PrintReportController);

	// 定义接口
public:
	// 定义一个报告打印确认接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("print.get.print"), modifyPrintReport, Uint64JsonVO::Wrapper);
	// 定义接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/printConfire", modifyPrintReport, BODY_DTO(PrintReportDTO::Wrapper, dto), execModifyPrintReport(dto));




private:
	// 报告打印 
	StringJsonVO::Wrapper execModifyPrintReport(const PrintReportDTO::Wrapper& dto);

};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRINTREPORT_CONTROLLER_H_
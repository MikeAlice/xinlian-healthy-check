#pragma once

#ifndef _PRINTREPORT_CONTROLLER_H_
#define _PRINTREPORT_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/printreport/PrintReportQuery.h"
#include "domain/dto/printreport/PrintReportDTO.h"
#include "domain/vo/printreport/PrintReportVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
 * ��ӡPDF����
 */
class PrintReportController : public oatpp::web::server::api::ApiController // 1 
{
	// ����������������
	API_ACCESS_DECLARE(PrintReportController);

	// ����ӿ�
public:
	// ����һ�������ӡȷ�Ͻӿ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("print.get.print"), modifyPrintReport, Uint64JsonVO::Wrapper);
	// ����ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/printConfire", modifyPrintReport, BODY_DTO(PrintReportDTO::Wrapper, dto), execModifyPrintReport(dto));




private:
	// �����ӡ 
	StringJsonVO::Wrapper execModifyPrintReport(const PrintReportDTO::Wrapper& dto);

};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRINTREPORT_CONTROLLER_H_
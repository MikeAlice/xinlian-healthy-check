#pragma once
#ifndef _PRINTMORE_CONTROLLER_
#define _PRINTMORE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/printmore/PrintMoreDTO.h"
#include "domain/vo/printmore/PrintMoreVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

class PrintMoreController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PrintMoreController);
	// 3 ����ӿ�
public:
	// 3.1 �������ؽӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("printmore.download-printmore.summary"), downloadPrintMore, ResultJsonVO::Wrapper);
	// 3.2 �������ؽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/healthcertificate-manage/download-printmore", downloadPrintMore, BODY_DTO(List<PrintMoreDTO::Wrapper>, dto), execDownloadPrintMore(dto));
private:
	ResultJsonVO::Wrapper execDownloadPrintMore(const List<PrintMoreDTO::Wrapper>& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRINTMORE_CONTROLLER_
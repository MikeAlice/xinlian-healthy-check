#pragma once
#ifndef _PrintConfirmController_
#define _PrintConfirmController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/printconfirm/PrintConfirmDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PrintConfirmController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PrintConfirmController);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("printconfirm.put.summary"), modifyPrintConfirm, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/healthcertificate-manage/modify-printconfirm", modifyPrintConfirm, BODY_DTO(List<String>, dto), execModifyPrintConfirm(dto));
private:
	// 3.3 ��ʾ�޸�����
	StringJsonVO::Wrapper execModifyPrintConfirm(const List<String>& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
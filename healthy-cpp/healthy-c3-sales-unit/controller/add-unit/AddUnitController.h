#pragma once

#ifndef _ADDUNITCONTROLLER_H_
#define _ADDUNITCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/update-unit/UnitDetailDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ������λ    �����ˣ�duxlong
 */
class AddUnitController: public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(AddUnitController);
public: // 3 ����ӿ�
// 	// 3.1 ����ӿ�����
// 	// 3.2 ����ӿڴ���
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unit.post.summary"), add, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/sales/unit/add", add, BODY_DTO(UnitDetailDTO::Wrapper, dto), execAddUnit(dto, authObject->getPayload()));

private: // 3.3 ����ӿ�ִ�к���
	StringJsonVO::Wrapper execAddUnit(const UnitDetailDTO::Wrapper& dto, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_ADDUNITCONTROLLER_H_

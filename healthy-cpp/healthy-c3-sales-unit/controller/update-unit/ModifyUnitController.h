#pragma once

#ifndef _MODIFYUNITCONTROLLER_H_
#define _MODIFYUNITCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/update-unit/UnitDetailDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ModifyUnitController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ModifyUnitController);

public: // 3 ����ӿ�
// 	// 3.1 ����ӿ�����
// 	// 3.2 ����ӿڴ���

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unit.put.summary"), modifyUnit, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/sales/unit/update", modifyUnit, BODY_DTO(UnitDetailDTO::Wrapper, dto), execModifyUnit(dto, authObject->getPayload()));

private: // ����ӿ�ִ�к���
	//ǰ�ˡ�UnitDetailDTO����ˡ�Uint64JsonVO��ǰ��
	StringJsonVO::Wrapper execModifyUnit(const UnitDetailDTO::Wrapper& dto, const PayloadDTO& payload);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_MODIFYUNITCONTROLLER_H_


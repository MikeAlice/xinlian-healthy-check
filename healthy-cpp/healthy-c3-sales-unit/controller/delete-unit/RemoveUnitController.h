#pragma once

#ifndef _REMOVEUNITCONTROLLER_H_
#define _REMOVEUNITCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/delete-unit/RemoveUnitDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ɾ����λ��֧������ɾ����    �����ˣ��޺�Ρ
 */
class RemoveUnitController: public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(RemoveUnitController);
public: // 3 ����ӿ�

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("unit.delete.summary"), removeUnit, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sales/unit/delete", removeUnit, BODY_DTO(List<RemoveUnitDTO::Wrapper>, dto), execRemoveUnit(dto, authObject->getPayload()));
/*
BODY_DTOʾ��
[
  {
	"id": "xxx"
  },
  {
	"id": "xxxxx"
  }
]
*/
private: // 3.3 ����ӿ�ִ�к���
	// ɾ������
	StringJsonVO::Wrapper execRemoveUnit(const List<RemoveUnitDTO::Wrapper>& dto, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_REMOVEUNITCONTROLLER_H_

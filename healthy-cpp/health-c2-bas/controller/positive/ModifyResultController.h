#pragma once
#ifndef _MODIFY_RESULT_CONTROLLER_H_
#define _MODIFY_RESULT_CONTROLLER_H_

#include "domain/dto/positive/ModifyResultDTO.h"
#include "domain/vo/positive/ModifyResultVO.h"
#include "../../domain/query/positive/ModifyResult.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ModifyResultController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
    //������������ʽӿ�
    API_ACCESS_DECLARE(ModifyResultController);
    //����ӿ�
public:

	// �����޸��û���Ϣ�˵�����
	ENDPOINT_INFO(modifyResult) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("modify.put.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ModifyResultJasonVO);
		// �����޸Ĳ�ѯ��������
		API_DEF_ADD_QUERY_PARAMS(Int32, "id", ZH_WORDS_GETTER("modify.field.id"), 100, false);
	}
	
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/positive/modify-result", modifyResult,
		BODY_DTO(ModifyResultDTO::Wrapper, dto), execModifyResult(dto));

private:

	ModifyResultJasonVO::Wrapper execModifyResult(const ModifyResultDTO::Wrapper& modify);
};

    // 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MODIFYRESULTCONTROLLER_H_
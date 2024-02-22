#pragma once

#ifndef _SAVERES_CONTROLLER_
#define _SAVERES_CONTROLLER_

#include "domain/dto/saveres/SaveResDTO.h"
#include "../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../domain/dto/saveres/RPProCheckDTO.h"



// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class SaveResController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(SaveResController);
	// 3 ����ӿ�
public:
	// ��̨��Ŀ������ϸ����ӿ�
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addDepartRes) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("save.post.addDepartRes"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT("POST", "/resultentry/addDepartRes", addDepartRes, BODY_DTO(SaveResDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddDepartRes(dto, authObject->getPayload()));
	}

	// ����ȷ�Ͻӿ�
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addRPProCheck) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("save.post.addRPProCheck"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT("POST", "/resultentry/addRPProCheck", addRPProCheck, BODY_DTO(RPProCheckDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddRPProCheck(dto));
	}


	// ��Ŀ����ӿ�
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("save.put.waiveCheck"), waiveCheck, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/resultentry/modifywaiveCheck", waiveCheck, BODY_DTO(RPProCheckDTO::Wrapper, dto), execModifyWaiveCheck(dto));
	
private:
	
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddDepartRes(const SaveResDTO::Wrapper& dto, const PayloadDTO& payload);
	// ����ȷ��
	Uint64JsonVO::Wrapper execAddRPProCheck(const RPProCheckDTO::Wrapper& dto);
	// ������Ŀ
	Uint64JsonVO::Wrapper execModifyWaiveCheck(const RPProCheckDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAVERES_CONTROLLER_
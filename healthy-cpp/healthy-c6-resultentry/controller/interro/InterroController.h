#pragma once
#ifndef _INTERRO_CONTROLLER_
#define _INTERRO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/interro/InterroQuery.h"
#include "domain/dto/interro/InterroDTO.h"
#include "domain/vo/interro/InterroVO.h"
/*
* Interro����������ȡ֢״��ѯ
*/

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
class InterroController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(InterroController); //�޲ι���
public:
	// ����֢״��ѯ �����ˣ�ʸ��
	// ���������ӿ�����
	ENDPOINT_INFO(addInterro) {
		//����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("interro.post.summary"));
		//����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		
	}

	// ���������ӿ�����
	ENDPOINT(API_M_POST, "/resultentry/Interro", addInterro, BODY_DTO(InterroDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddInterro(dto));
	}
private:
	Uint64JsonVO::Wrapper execAddInterro(const InterroDTO::Wrapper& dto);
};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _INTERRO_CONTROLLER_

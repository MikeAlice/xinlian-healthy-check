#pragma once

#ifndef _COMBOCONTROLLER_H_
#define _COMBOCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/combo/AddPackVO.h"
#include "domain/vo/combo/DelPackVO.h"
#include "domain/vo/combo/UpdatePackVO.h"
#include "../../service/combo/addPack/AddPackService.h"
#include "../../service/combo/delPack/DelPackService.h"
#include "../../service/combo/updatePack/UpdatePackService.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ComboController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ComboController);
public:// ����ӿ�

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addPack) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("combo.addPack"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/combo/add-pack", addPack, BODY_DTO(AddPackDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddPack(dto));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(delPack) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("combo.delPack"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_DEL, "/combo/del-pack", delPack, BODY_DTO(DelPackDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execDelPack(dto));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(updatePack) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("combo.updatePack"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/combo/update-pack", updatePack, BODY_DTO(UpdatePackDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execUpdatePack(dto));
	}
private:// ����ӿ�ִ�к���
	//��������
	Uint64JsonVO::Wrapper execAddPack(const AddPackDTO::Wrapper& dto);
	//ɾ������
	Uint64JsonVO::Wrapper execDelPack(const DelPackDTO::Wrapper& dto);
	//�޸�����
	Uint64JsonVO::Wrapper execUpdatePack(const UpdatePackDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _COMBOCONTROLLER_H_
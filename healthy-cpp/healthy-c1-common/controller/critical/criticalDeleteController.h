#pragma once
#ifndef _CRITICALDELETECONTROLLER_H_
#define _CRITICALDELETECONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/critical/CriticalDeleteVO.h"
#include "../../domain/query/critical/CriticalQuery.h"
#include "../../domain/dto/critical/CriticalDeleteDTO.h"



#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class CriticalDeleteController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(CriticalDeleteController);
public:

	// ����Σ��ֵ�б��ѯ�ӿ�����
	ENDPOINT_INFO(deleteCritical) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("critical.delete.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//����Σ��ֵɾ���б�ӿ�
	ENDPOINT(API_M_DEL, "/critical/query-delete-critical", deleteCritical, BODY_DTO(CriticalDeleteListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDeleteCritical(dto));
	};
	
private:
	//����ӿ�ִ�к���
	Uint64JsonVO::Wrapper execDeleteCritical(const CriticalDeleteListDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_

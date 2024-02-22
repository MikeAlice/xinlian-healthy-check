#pragma once

#ifndef _GROUPITEMIGNO_CONTROLLER_
#define _GROUPITEMIGNO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/groupItemIgno/GroupItemIgnoDTO.h"
//#include "../../healthy-cpp/lib-oatpp/include/ApiHelper.h"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class GroupItemIgnoController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(GroupItemIgnoController);
 
public:
 
	// 3.1 �����޸Ľӿ�����
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("groupItemIgno.update.summary"), updateItem, Uint64JsonVO::Wrapper);
		// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(updateItem) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("groupItemIgno.update.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		
		// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "orderGroupItemProjectId", ZH_WORDS_GETTER("groupItemIgno.field.orderGroupItemProjectId"), "v789zd7f98saf79s78a", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("groupItemIgno.field.personId"), "0000 <- failtest", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "updateId", ZH_WORDS_GETTER("groupItemIgno.field.updateId"), "3478237482374", true);
 
	}



	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/healthy-c7-common/update-depart-item-result", updateItem, BODY_DTO(GroupItemIgnoDTO::Wrapper, dto), execUpdateDepartItemResult(dto));
	  
private:
 
	// 3.3 ��ʾ�޸�����
	StringJsonVO::Wrapper execUpdateDepartItemResult(const GroupItemIgnoDTO::Wrapper& dto);
 
};

 
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
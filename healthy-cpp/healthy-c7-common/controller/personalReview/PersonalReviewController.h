#pragma once

#ifndef _PERSONALREVIEW_CONTROLLER_
#define _PERSONALREVIEW_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/personalReview/PersonalReviewDTO.h"
//#include "../../healthy-cpp/lib-oatpp/include/ApiHelper.h"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen



class PersonalReviewController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PersonalReviewController);

public:

	/**
 * API�������壬�����ʱ�������Ȩ����
 * @param __TITLE__: Api��������
 * @param __ENDPOINT_FUN_NAME__: Api�˵㺯������
 * @param __RESP_TYPE__: ��Ӧ���������磺XxxJsonVO
 */
//#define API_DEF_ENDPOINT_INFO_AUTH(__TITLE__, __ENDPOINT_FUN_NAME__, __RESP_TYPE__) \
//ENDPOINT_INFO(__ENDPOINT_FUN_NAME__) { \
//	info->summary = __TITLE__; \
//	API_DEF_ADD_AUTH(); \
//	API_DEF_ADD_RSP_JSON(__RESP_TYPE__); \
//}


	// 3.1 �����޸Ľӿ�����
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("groupItemIgno.update.summary"), updateItem, Uint64JsonVO::Wrapper);
		// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(updateGroupPerson) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("personalReview.update.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		// ����������ѯ��������
		/*API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("personalReview.field.personId"), "0000 <- failtest", true);
		API_DEF_ADD_QUERY_PARAMS(String, "updateId", ZH_WORDS_GETTER("personalReview.field.updateId"), "3478237482374", true);*/

	}



	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/healthy-c7-common/update-personal-review", updateGroupPerson, BODY_DTO(PersonalReviewDTO::Wrapper, dto), execUpdatePersonalReview(dto));


	// 3.1 �����޸Ľӿ�����
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sample.put.summary"), modifySample, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/sample", modifySample, BODY_DTO(std::string, dto), execModifySample(dto));


private:

	// 3.3 ��ʾ�޸�����
	StringJsonVO::Wrapper execUpdatePersonalReview(const PersonalReviewDTO::Wrapper& dto);

	// 3.3 ��ʾ�޸�����
	//Uint64JsonVO::Wrapper execModifySample(std::string dto)
	//{
	//	auto jvo = Uint64JsonVO::createShared();
	//	return jvo;
	//}

};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
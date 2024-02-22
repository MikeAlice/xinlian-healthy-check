#pragma once

#ifndef _PERSONALREVIEW_CONTROLLER_
#define _PERSONALREVIEW_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/personalReview/PersonalReviewDTO.h"
//#include "../../healthy-cpp/lib-oatpp/include/ApiHelper.h"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen



class PersonalReviewController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PersonalReviewController);

public:

	/**
 * API描述定义，定义的时候添加授权定义
 * @param __TITLE__: Api描述标题
 * @param __ENDPOINT_FUN_NAME__: Api端点函数名称
 * @param __RESP_TYPE__: 响应数据类型如：XxxJsonVO
 */
//#define API_DEF_ENDPOINT_INFO_AUTH(__TITLE__, __ENDPOINT_FUN_NAME__, __RESP_TYPE__) \
//ENDPOINT_INFO(__ENDPOINT_FUN_NAME__) { \
//	info->summary = __TITLE__; \
//	API_DEF_ADD_AUTH(); \
//	API_DEF_ADD_RSP_JSON(__RESP_TYPE__); \
//}


	// 3.1 定义修改接口描述
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("groupItemIgno.update.summary"), updateItem, Uint64JsonVO::Wrapper);
		// 3.1 定义查询接口描述
	ENDPOINT_INFO(updateGroupPerson) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("personalReview.update.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		// 定义其他查询参数描述
		/*API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("personalReview.field.personId"), "0000 <- failtest", true);
		API_DEF_ADD_QUERY_PARAMS(String, "updateId", ZH_WORDS_GETTER("personalReview.field.updateId"), "3478237482374", true);*/

	}



	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/healthy-c7-common/update-personal-review", updateGroupPerson, BODY_DTO(PersonalReviewDTO::Wrapper, dto), execUpdatePersonalReview(dto));


	// 3.1 定义修改接口描述
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sample.put.summary"), modifySample, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/sample", modifySample, BODY_DTO(std::string, dto), execModifySample(dto));


private:

	// 3.3 演示修改数据
	StringJsonVO::Wrapper execUpdatePersonalReview(const PersonalReviewDTO::Wrapper& dto);

	// 3.3 演示修改数据
	//Uint64JsonVO::Wrapper execModifySample(std::string dto)
	//{
	//	auto jvo = Uint64JsonVO::createShared();
	//	return jvo;
	//}

};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
#pragma once
#ifndef _SAVE_INFO_CONTROLLER_H_
#define _SAVE_INFO_CONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/Exalanding/SaveInfoQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/Exalanding/SaveInfoVO.h"
#include "domain/dto/Exalanding/SaveInfoDTO.h"
//#include "domain/vo/user/MenuVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class SaveInfoController : public oatpp::web::server::api::ApiController
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(SaveInfoController);
	// 3 定义接口
public:
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addSample) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("exalanding.saveinfo.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);

		

		// 定义其他查询参数描述
		/*API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("exalanding.saveinfo.field.id"), "key word", false);
		API_DEF_ADD_QUERY_PARAMS(String, "id_card", ZH_WORDS_GETTER("exalanding.saveinfo.field.id_card"), "ZhangSan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "person_name", ZH_WORDS_GETTER("exalanding.saveinfo.field.person_name"), "342501200208140011", false);
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("exalanding.saveinfo.field.sex"), "man", false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "age", ZH_WORDS_GETTER("exalanding.saveinfo.field.age"), 22, false);
		API_DEF_ADD_QUERY_PARAMS(String, "mobile", ZH_WORDS_GETTER("exalanding.saveinfo.field.mobile"), "17653640329", false);
		API_DEF_ADD_QUERY_PARAMS(String, "is_marry", ZH_WORDS_GETTER("exalanding.saveinfo.field.is_marry"), "Single", false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "is_pass", ZH_WORDS_GETTER("exalanding.saveinfo.field.is_pass"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "physical_type", ZH_WORDS_GETTER("exalanding.saveinfo.field.physical_type"), "health", false);*/
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/sample-SaveInfo", addSample, BODY_DTO(SaveInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddUserInfo(dto));
	}
	
private:
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddUserInfo(const SaveInfoDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _SAVE_INFO_CONTROLLER_H_
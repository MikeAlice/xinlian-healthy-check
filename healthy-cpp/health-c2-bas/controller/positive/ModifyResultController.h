#pragma once
#ifndef _MODIFY_RESULT_CONTROLLER_H_
#define _MODIFY_RESULT_CONTROLLER_H_

#include "domain/dto/positive/ModifyResultDTO.h"
#include "domain/vo/positive/ModifyResultVO.h"
#include "../../domain/query/positive/ModifyResult.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ModifyResultController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
    //定义控制器访问接口
    API_ACCESS_DECLARE(ModifyResultController);
    //定义接口
public:

	// 定义修改用户信息端点描述
	ENDPOINT_INFO(modifyResult) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("modify.put.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ModifyResultJasonVO);
		// 定义修改查询参数描述
		API_DEF_ADD_QUERY_PARAMS(Int32, "id", ZH_WORDS_GETTER("modify.field.id"), 100, false);
	}
	
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/positive/modify-result", modifyResult,
		BODY_DTO(ModifyResultDTO::Wrapper, dto), execModifyResult(dto));

private:

	ModifyResultJasonVO::Wrapper execModifyResult(const ModifyResultDTO::Wrapper& modify);
};

    // 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MODIFYRESULTCONTROLLER_H_
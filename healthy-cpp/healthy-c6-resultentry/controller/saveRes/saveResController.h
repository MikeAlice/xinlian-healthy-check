#pragma once

#ifndef _SAVERES_CONTROLLER_
#define _SAVERES_CONTROLLER_

#include "domain/dto/saveres/SaveResDTO.h"
#include "../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../domain/dto/saveres/RPProCheckDTO.h"



// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class SaveResController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(SaveResController);
	// 3 定义接口
public:
	// 诊台项目及其明细保存接口
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addDepartRes) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("save.post.addDepartRes"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT("POST", "/resultentry/addDepartRes", addDepartRes, BODY_DTO(SaveResDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddDepartRes(dto, authObject->getPayload()));
	}

	// 到检确认接口
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addRPProCheck) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("save.post.addRPProCheck"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT("POST", "/resultentry/addRPProCheck", addRPProCheck, BODY_DTO(RPProCheckDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddRPProCheck(dto));
	}


	// 项目弃检接口
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("save.put.waiveCheck"), waiveCheck, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/resultentry/modifywaiveCheck", waiveCheck, BODY_DTO(RPProCheckDTO::Wrapper, dto), execModifyWaiveCheck(dto));
	
private:
	
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddDepartRes(const SaveResDTO::Wrapper& dto, const PayloadDTO& payload);
	// 到检确认
	Uint64JsonVO::Wrapper execAddRPProCheck(const RPProCheckDTO::Wrapper& dto);
	// 弃检项目
	Uint64JsonVO::Wrapper execModifyWaiveCheck(const RPProCheckDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAVERES_CONTROLLER_
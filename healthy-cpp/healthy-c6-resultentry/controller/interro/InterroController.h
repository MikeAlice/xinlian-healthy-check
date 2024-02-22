#pragma once
#ifndef _INTERRO_CONTROLLER_
#define _INTERRO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/interro/InterroQuery.h"
#include "domain/dto/interro/InterroDTO.h"
#include "domain/vo/interro/InterroVO.h"
/*
* Interro控制器：获取症状问询
*/

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
class InterroController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(InterroController); //无参构造
public:
	// 保存症状问询 负责人：矢量
	// 定义新增接口描述
	ENDPOINT_INFO(addInterro) {
		//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("interro.post.summary"));
		//定义默认授权参数
		API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		
	}

	// 定义新增接口描述
	ENDPOINT(API_M_POST, "/resultentry/Interro", addInterro, BODY_DTO(InterroDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddInterro(dto));
	}
private:
	Uint64JsonVO::Wrapper execAddInterro(const InterroDTO::Wrapper& dto);
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _INTERRO_CONTROLLER_

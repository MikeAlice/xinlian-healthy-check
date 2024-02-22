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
	//定义控制器访问入口
	API_ACCESS_DECLARE(CriticalDeleteController);
public:

	// 定义危险值列表查询接口描述
	ENDPOINT_INFO(deleteCritical) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("critical.delete.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//定义危机值删除列表接口
	ENDPOINT(API_M_DEL, "/critical/query-delete-critical", deleteCritical, BODY_DTO(CriticalDeleteListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDeleteCritical(dto));
	};
	
private:
	//定义接口执行函数
	Uint64JsonVO::Wrapper execDeleteCritical(const CriticalDeleteListDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_

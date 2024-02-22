#pragma once
#ifndef _CRITICALMODIFYCONTROLLER_H_
#define _CRITICALMODIFYCONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/critical/CriticalModifyVO.h"
#include "../../domain/query/critical/CriticalQuery.h"
#include "domain/dto/critical/CriticalModifyDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class CriticalModifyController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(CriticalModifyController);
public:

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("critical.put.summary"), modifySample, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/critcal", modifySample, BODY_DTO(CriticalListDTO::Wrapper, dto), execModifyCritical(dto));
private:
	//定义接口执行函数
	Uint64JsonVO::Wrapper execModifyCritical(const CriticalListDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_
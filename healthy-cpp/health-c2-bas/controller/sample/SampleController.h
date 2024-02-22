#pragma once
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/sample/SampleDTO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

//单位分页查询实体
class SampleController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(SampleController);

public://定义接口

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sample.put.summary"), modifySample, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/sample", modifySample, BODY_DTO(SampleDTO::Wrapper, dto), execModifySample(dto));

private://定义接口执行函数

	// 3.3 演示修改数据
	StringJsonVO::Wrapper execModifySample(const SampleDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController)

#endif
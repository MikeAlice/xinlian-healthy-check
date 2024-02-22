#pragma once
#ifndef _ObtainSampleList_CONTROLLER_
#define _ObtainSampleList_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/sample/ObtainSampleListQuery.h"
#include "domain/dto/sample/ObtainSampleListDTO.h"
#include "domain/vo/sample/ObtainSampleListVO.h"
//ObtainSampleListController
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen



class ObtainSampleListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ObtainSampleListController);
	// 3 定义接口
public:

	ENDPOINT_INFO(queryObtainSampleList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sample.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ObtainSampleListJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		// 
		//查询类型
		//obsl=ObtainSampleList
		API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("sample.obsl.type"), 1, true);

		//名称
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.obsl.name"), "name0", false);
		//样本代码
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("sample.obsl.code"), "0000", false);
		//关联码
		API_DEF_ADD_QUERY_PARAMS(String, "liscode", ZH_WORDS_GETTER("sample.obsl.liscode"), "0000", false);


	}

	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/sample/ObtainSampleList", queryObtainSampleList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, ObtainSampleListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySample(uq));
	}

	

private:
	// 3.3 分页查询数据
	ObtainSampleListPageJsonVO::Wrapper execQuerySample(const ObtainSampleListQuery::Wrapper& query);
	
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
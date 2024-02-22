#pragma once
#ifndef _JobNameList_Controller_
#define _JobNameList_Controller_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/jobnamelist/JobNameListQuery.h"
#include "domain/dto/jobnamelist/JobNameListDTO.h"
#include "domain/vo/jobnamelist/JobNameListVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class JobNameListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(JobNameListController);
	// 3 定义接口
public:
	// 3.1 定义测试声明式服务调用的接口1描述
	ENDPOINT_INFO(queryJobNameList) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("jobnamelist.query-jobnamelist.summary"), JobNameListPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他路径参数说明
		API_DEF_ADD_QUERY_PARAMS(String, "keyword", ZH_WORDS_GETTER("jobnamelist.field.keyword"), "", false);
	}
	// 3.2 定义测试声明式服务调用的接口1处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/common/query-jobnamelist", queryJobNameList, JobNameListQuery, execQueryJobNameList(query, authObject->getPayload()));
private:
	// 3.3 测试声明式服务调用1
	JobNameListPageJsonVO::Wrapper execQueryJobNameList(const JobNameListQuery::Wrapper & query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
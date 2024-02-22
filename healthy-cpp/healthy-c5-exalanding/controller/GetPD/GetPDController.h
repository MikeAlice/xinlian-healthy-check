#pragma once
#ifndef _GETPD_CONTROLLER_
#define _GETPD_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/GetPD/GetPDQuery.h"
#include "domain/dto/GetPD/GetPDDTO.h"
#include "domain/vo/GetPD/GetPDVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class GetPDController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(GetPDController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryGetPD) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("GetPD.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetPDPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("GetPD.field.name"), "aaa", true);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "id_card", ZH_WORDS_GETTER("GetPD.field.id_card"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "id", ZH_WORDS_GETTER("GetPD.field.id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "work_name", ZH_WORDS_GETTER("GetPD.field.work_name"), "N", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/GetPD", queryGetPD, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetPDQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGetPD(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 演示分页查询数据
	GetPDPageJsonVO::Wrapper execQueryGetPD(const GetPDQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
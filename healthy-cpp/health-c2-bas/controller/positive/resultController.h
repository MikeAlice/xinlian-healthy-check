#ifndef _RESULTCONTROLLER_H_
#define _RESULTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/positive/resultListVO.h"
#include "../../domain/query/positive/resultListQuery.h"
#include "../../domain/dto/positive/resultListDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class resultController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(resultController);
public: // 定义接口

	// 定义查询接口描述
	ENDPOINT_INFO(queryResultList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("positive.result.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(resultListJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("positive.result.field.id"), "1", true);
		API_DEF_ADD_QUERY_PARAMS(String, "condition", ZH_WORDS_GETTER("positive.result.field.condition"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "genderAppropriate", ZH_WORDS_GETTER("positive.result.field.genderAppropriate"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "positiveId", ZH_WORDS_GETTER("positive.result.field.positiveId"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "judgmentCondition", ZH_WORDS_GETTER("positive.result.field.judgmentCondition"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "excludePositive", ZH_WORDS_GETTER("positive.result.field.excludePositive"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("positive.result.field.type"), "xxx", false);
		
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/positive/query-resultList", queryResultList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(resQuery, resultListQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryResult(resQuery,authObject->getPayload()));
	}

	// 定义删除接口描述
	ENDPOINT_INFO(removeSample) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("positive.remove.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("positive.remove.field.id"), 1, true);
	}
	// 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/positive/{id}", removeSample, PATH(UInt64, id), execRemoveResult(id));


private: // 定义接口执行函数
	resultListJsonVO::Wrapper execQueryResult(const resultListQuery::Wrapper& id, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execRemoveResult(const UInt64& id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_RESULTCONTROLLER_H_
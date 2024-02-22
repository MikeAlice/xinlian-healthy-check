#ifndef _RESRULECONTROLLER_H_
#define _RESRULECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/positive/resRuleListVO.h"
#include "../../domain/vo/positive/ruleListVO.h"
#include "../../domain/query/positive/resRuleListQuery.h"
#include "../../domain/query/positive/ruleListQuery.h"
#include "../../domain/dto/positive/resRuleListDTO.h"
#include "../../domain/dto/positive/ruleListDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class resRuleController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(resRuleController);
public: // 定义接口
	// 定义查询结果规则列表接口描述
	ENDPOINT_INFO(queryResRuleList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("positive.resRules.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(resRuleListJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("positive.resRules.field.id"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "condition", ZH_WORDS_GETTER("positive.resRules.field.condition"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "genderAppropriate", ZH_WORDS_GETTER("positive.resRules.field.genderAppropriate"), "genderAppropriate", false);
		API_DEF_ADD_QUERY_PARAMS(String, "positiveId", ZH_WORDS_GETTER("positive.resRules.field.positiveId"), "positiveId", false);
		API_DEF_ADD_QUERY_PARAMS(String, "judgmentCondition", ZH_WORDS_GETTER("positive.resRules.field.judgmentCondition"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "excludePositive", ZH_WORDS_GETTER("positive.resRules.field.excludePositive"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("positive.resRules.field.type"), "xxx", false);
	}
	// 定义查询结果规则列表接口
	ENDPOINT(API_M_GET, "/positive/query-resRuleList", queryResRuleList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(resQuery, resRuleListQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryResRule(resQuery));
	}
	// 定义查询结果规则对应的阳性规则列表接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("positive.rules.query.summary"), queryRuleList, Uint64JsonVO::Wrapper);
	// 定义接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "positive/query-ruleList", queryRuleList, BODY_STRING(String, id), execQueryRule(id));

	// 定义删除接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("positive.resRules.remove.summary"), removeResRuleList, Uint64JsonVO::Wrapper);
	// 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "positive/remove-resRuleList", removeResRuleList, BODY_STRING(String, id), execRemoveResRule(id));

	// 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("positive.resRules.modify.summary"), modifyResRuleList, Uint64JsonVO::Wrapper);
	// 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "positive/modify-resRuleList", modifyResRuleList, BODY_DTO(rulePageDTO::Wrapper, dto), execModifyResRule(dto));
	
private: // 定义接口执行函数
	resRuleListJsonVO::Wrapper execQueryResRule(const resRuleListQuery::Wrapper& query); 
	resRuleListJsonVO::Wrapper execQueryRule(const String& id);
	Uint64JsonVO::Wrapper execRemoveResRule(const String& id);
	Uint64JsonVO::Wrapper execModifyResRule(const rulePageDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_RESRULECONTROLLER_H_
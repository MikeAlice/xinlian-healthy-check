#pragma once
#ifndef _PERSON_CONTROLLER_
#define _PERSON_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "../../domain/vo/checkitem/PersonVO.h"
#include "../../domain/query/checkitem/PersonQuery.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class PersonController : public oatpp::web::server::api::ApiController {
	//定义控制器访问入口
	API_ACCESS_DECLARE(PersonController);
public:	//定义接口

	//定义分页查询单位列表接口描述
	ENDPOINT_INFO(queryPerson) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("checkitem.filed.person_summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PersonJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("checkitem.person.id"), ZH_WORDS_GETTER("checkitem.person.eg_id"), true);
	}

	//定义分页查询单位列表接口
	ENDPOINT(API_M_GET, "/resultentry/checkitem/query-person", queryPerson, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(pq, PersonQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPerson(pq));
	}

private:	//定义接口执行函数
	PersonPageJsonVO::Wrapper execQueryPerson(const PersonQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _Person_CONTROLLER_
#pragma once
#ifndef _DEPARTCONTROLLER_H_
#define _DEPARTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Dangerous/DepartQuery.h"
#include "domain/dto/Dangerous/DepartListDTO.h"
#include "domain/vo/Dangerous/DepartVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class DepartController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(DepartController);
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryDepart) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Dangerous.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DepartListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//体检人员ID
		API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("depart.field.officeName"), "c82624d2a32bc9f711c62fa80f50df60", true);

	}

	ENDPOINT(API_M_GET, "/Dangerous/query-depart", queryDepart, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
	// 解析查询参数为Query领域模型
	API_HANDLER_QUERY_PARAM(qd, DepartQuery, params);
	// 呼叫执行函数响应结果
	API_HANDLER_RESP_VO(execQueryDepart(qd));
	}
private:
	DepartListPageJsonVO::Wrapper execQueryDepart(const DepartQuery::Wrapper& query);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITQUERY_H_
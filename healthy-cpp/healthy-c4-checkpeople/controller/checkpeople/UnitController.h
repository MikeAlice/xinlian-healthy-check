#pragma once
#ifndef _UNITCONTROLLER_H_
#define _UNITCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/unitpeople/UnitPeopleVO.h"
#include "../../domain/query/unitpeople/UnitPeoPleQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class UnitController : public oatpp::web::server::api::ApiController
{
	//1.定义控制器访问入口
	API_ACCESS_DECLARE(UnitController);

public:// 定义接口 
	//3.定义查询接口描述
	ENDPOINT_INFO(queryUnit)
	{
		//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.query.summary"));
		//定义默认授权参数（可选定义，如果定义了，下面的ENDPOINT需要加入API_HANDLER_AUTH_PARAM）
		API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(UnitPeoplePageJsonVO); //响应的是分页查询数据的格式
		//定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "idCard", ZH_WORDS_GETTER("unit.field.idCard"), "511321XXXXXXXXXXXX", true);
	}  

	//2.定义分页查询单位列表接口
	ENDPOINT(API_M_GET, "/query_people", queryUnit, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		//解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, UnitPeopleQuery, params);
		//呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryUnit(uq));
	}
private://定义接口执行函数
	//分页查询数据
	UnitPeoplePageJsonVO::Wrapper execQueryUnit(const UnitPeopleQuery::Wrapper& query);
	
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_UNITCONTROLLER_H_
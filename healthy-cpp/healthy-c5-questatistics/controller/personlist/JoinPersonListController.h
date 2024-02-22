#pragma once

#ifndef _JoinPersonListController_H_
#define _JoinPersonListController_H_

#include "domain/vo/BaseJsonVO.h"
#include"../../domain/vo/personlist/JoinPersonListVO.h"
#include"../../domain/query/personlist/JoinPersonListQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController) 


	class JoinPersonListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(JoinPersonListController);
	// 3 定义接口
public:
	// 3.1 定义分页查询单位列表接口描述
	ENDPOINT_INFO(queryPersonList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("check.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PersonListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//查询类型
		API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("check.field.type"), 1, true);
		//体检编号
		API_DEF_ADD_QUERY_PARAMS(UInt32, "testNum", ZH_WORDS_GETTER("check.field.testNum"), 23, false);
		//检查种类
		API_DEF_ADD_QUERY_PARAMS(String, "checkClass", ZH_WORDS_GETTER("check.field.checkClass"), "zzz", false);
		//姓名
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("check.field.name"), "hhh", false);
		//身份证号
		API_DEF_ADD_QUERY_PARAMS(UInt32, "idCard", ZH_WORDS_GETTER("check.field.idCard"), 111, false);
		//危害因素
		API_DEF_ADD_QUERY_PARAMS(String, "hazardFactor", ZH_WORDS_GETTER("check.field.hazardFactor"), "222", false);
		//状态
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("check.field.status"), "aaa", false);
		//性别
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("check.field.sex"), "fa", false);
		//体检日期
		API_DEF_ADD_QUERY_PARAMS(UInt32, "checkDate", ZH_WORDS_GETTER("check.field.checkDate"), 22, false);
		//体检结论
		API_DEF_ADD_QUERY_PARAMS(String, "comments", ZH_WORDS_GETTER("check.field.comments"), "ydy", false);
	}
	//定义分页查询单位列表接口
	ENDPOINT(API_M_GET, "/personlist/query-check", queryPersonList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, JoinPersonListQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPersonList(uq));
	}
private:
	PersonListPageJsonVO::Wrapper execQueryPersonList(const JoinPersonListQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_

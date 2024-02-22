#pragma once
#ifndef _ADDCONTROLLER_H_
#define _ADDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/add/AddVo.h"
#include "../../domain/query/add/AddUnit.h"
#include "../../domain/dto/add/AddUnitDTO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class AddController :public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(AddController);
	//定义接口
public:
	/*
	//定义查询接口描述
	ENDPOINT_INFO(queryAdd) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("add.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AddPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt32, "type", ZH_WORDS_GETTER("use.field.type"), 12334, false);
		//身份证号
		API_DEF_ADD_QUERY_PARAMS(UInt32, "id", ZH_WORDS_GETTER("use.field.id"), 2345, false);
		//体检姓名
		API_DEF_ADD_QUERY_PARAMS(String, "u_name", ZH_WORDS_GETTER("use.field.u_name"), "2345", false);
		//性别
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("use.field.sex"), "2345", false);
		//年龄
		API_DEF_ADD_QUERY_PARAMS(UInt32, "age", ZH_WORDS_GETTER("use.field.age"), 1, false);
		//联系电话
		API_DEF_ADD_QUERY_PARAMS(UInt32, "linkPhone", ZH_WORDS_GETTER("use.field.linkPhone"), 1, false);
		//单位名称
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("use.field.name"), "2345", false);
		//婚姻状态
		API_DEF_ADD_QUERY_PARAMS(String, "marriage", ZH_WORDS_GETTER("use.field.marriage"), "2345", false);
		//分组名称
		API_DEF_ADD_QUERY_PARAMS(String, "g_name", ZH_WORDS_GETTER("use.field.g_name"), "2345", false);
	}

	//定义分页查询单位列表接口
	ENDPOINT(API_M_GET, "/add/query-add", queryAdd, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME){
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, AddUnit, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAdd(uq));
	}
	*/

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addUnit) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("add.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/updata-unit", addUnit, BODY_DTO(AddUnitDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddUnit(dto));
	}

	//定义接口执行函数
private:
	AddPageJsonVO::Wrapper execQueryAdd(const AddUnit::Wrapper& query);

	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddUnit(const AddUnitDTO::Wrapper& dto);
};
#include OATPP_CODEGEN_END(ApiController)

#endif
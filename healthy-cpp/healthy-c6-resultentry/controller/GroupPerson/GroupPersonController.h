#pragma once
#ifndef _GROUP_PERSON_CONTROLLER_
#define _GROUP_PERSON_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/GroupPerson/GroupPersonQuery.h"
#include "../../service/GroupPerson/GroupPersonService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "domain/GlobalInclude.h"
#include "domain/vo/GroupPerson/GroupPersonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GroupPersonController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GroupPersonController);
public: // 定义接口
	// 定义查询接口描述
	ENDPOINT_INFO(queryByGroupPerson) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("group_person.get.summary"));
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GroupPersonPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("group_person.data.name"), ZH_WORDS_GETTER("group_person.example.name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "test_num", ZH_WORDS_GETTER("group_person.data.test_num"), ZH_WORDS_GETTER("group_person.example.test_num"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "dept", ZH_WORDS_GETTER("group_person.data.dept"), ZH_WORDS_GETTER("group_person.example.dept"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "physical_type", ZH_WORDS_GETTER("group_person.data.physical_type"), ZH_WORDS_GETTER("group_person.example.physical_type"), false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "is_check", ZH_WORDS_GETTER("group_person.data.is_check"), 0, false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "is_recheck", ZH_WORDS_GETTER("group_person.data.is_recheck"), 0, false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_regist_date", ZH_WORDS_GETTER("group_person.data.start_regist_date"), ZH_WORDS_GETTER("group_person.example.start_regist_date"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "finish_regist_date", ZH_WORDS_GETTER("group_person.data.finish_regist_date"), ZH_WORDS_GETTER("group_person.example.finish_regist_date"), false);
	};

	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/resultentry/GroupPerson/Query/list", queryByGroupPerson, QUERIES(QueryParams, queryParams)) {
		// 将查询参数转换成PageQuery查询模型
		API_HANDLER_QUERY_PARAM(gpq, GroupPersonQuery, queryParams);
		// 执行业务逻辑处理
		API_HANDLER_RESP_VO(execQueryByGroupPerson(gpq));
	}
private: // 定义接口执行函数
	GroupPersonPageJsonVO::Wrapper execQueryByGroupPerson(const GroupPersonQuery::Wrapper& gpq);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GROUP_PERSON_CONTROLLER_
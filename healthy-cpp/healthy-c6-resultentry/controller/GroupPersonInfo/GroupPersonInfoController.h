#pragma once
#ifndef _GROUP_PERSON_INFO_CONTROLLER_
#define _GROUP_PERSON_INFO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/GroupPersonInfo/GroupPersonInfoVO.h"
#include "../../domain/query/GroupPersonInfo/GroupPersonInfoQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GroupPersonInfoController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GroupPersonInfoController);
public: // 定义接口
	// 定义人员详情查询接口描述
	ENDPOINT_INFO(queryPersonInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("group_person.get.info"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GroupPersonInfoJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "test_num", ZH_WORDS_GETTER("group_person.data.test_num"), ZH_WORDS_GETTER("group_person.example.test_num"), true);
	};


	// 定义人员详情查询接口
	ENDPOINT(API_M_GET, "/resultentry/GroupPerson/Query/info", queryPersonInfo, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(infoQuery, GroupPersonInfoQuery, params);
		API_HANDLER_RESP_VO(queryPersonInfo(infoQuery));
	}
private: // 定义接口执行函数
	// 定义人员详情查询接口函数
	GroupPersonInfoJsonVO::Wrapper queryPersonInfo(const GroupPersonInfoQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GROUP_PERSON_INFO_CONTROLLER_
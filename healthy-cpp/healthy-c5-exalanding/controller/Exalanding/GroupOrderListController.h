#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include"domain/query/Exalanding/GroupOrderListQuery.h"
#include "domain/dto/Exalanding/GroupOrderListDTO.h"
#include "domain/do/Exalanding/GroupOrderListDO.h"
#include"domain/vo/Exalanding/GroupOrderVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * 示例控制器，演示基础接口的使用
 */
class GroupOrderListController : public oatpp::web::server::api::ApiController 
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GroupOrderListController);
	// 定义接口
public:
	// 定义查询接口描述
	ENDPOINT_INFO(queryGroupOrder) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("exalanding.get.summary"));
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GroupOrderListJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("exalanding.field.sex"), "男", false);
		API_DEF_ADD_QUERY_PARAMS(String, "groupUnitName", ZH_WORDS_GETTER("exalanding.field.groupUnitName"), "xx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "groupName", ZH_WORDS_GETTER("exalanding.field.groupName"), "xx", false);
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/exalanding", queryGroupOrder, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(gq, GroupOrderListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryGroupOrder(gq, authObject->getPayload()));
	}
private:
	// 分页查询数据
	GroupOrderListPageJsonVO::Wrapper execQueryGroupOrder(const GroupOrderListQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
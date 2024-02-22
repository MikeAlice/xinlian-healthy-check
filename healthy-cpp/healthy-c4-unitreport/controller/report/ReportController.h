#ifndef _REPORTCONTROLLER_H_
#define _REPORTCONTROLLER_H_
#include"domain/vo/BaseJsonVO.h"
#include"../../domain/vo/report/ReportVO.h"
#include"../../domain/query/report/ReportQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class ReportController : public oatpp::web::server::api::ApiController {
	//定义控制器访问入口
	API_ACCESS_DECLARE(ReportController);
public:
	ENDPOINT_INFO(ReportCheck) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unit.choice"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ReportJsonVO);
		// 定义其他查询参数描述
		// 唯一编号
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("unit.id"), "XXXX", false);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/report-choice", ReportCheck, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, IDQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execqueryReport(userQuery));
	}

private:
	ReportJsonVO::Wrapper execqueryReport(const IDQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)
#endif  



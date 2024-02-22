#ifndef _HEALTH_CERTIFICATE_CONTROLLER_
#define _HEALTH_CERTIFICATE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/healthcertificatelist/HealthCertificateQuery.h"
#include "domain/dto/healthcertificatelist/HealthCertificateDTO.h" 
#include "domain/vo/healthcertificatelist/HealthCertificateVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 公用服务接口控制器，演示基础接口的使用
 */
class HealthCertificateController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(HealthCertificateController);
	// 3 定义接口
public:
	// 3.1 定义测试声明式服务调用的接口1描述
	ENDPOINT_INFO(queryHealthCertificateList) {
		// 接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("query-healthcertificatelist.get.summary"));
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应式参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(HealthCertificateListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();

		// 其他路径参数
		// 健康证编号
		API_DEF_ADD_QUERY_PARAMS(String, "health_ccertificate", ZH_WORDS_GETTER("query-healthcertificatelist.field.hcid"), "10008", false);
		// 登记时间范围（开始）
		API_DEF_ADD_QUERY_PARAMS(String, "start_date", ZH_WORDS_GETTER("query-healthcertificatelist.field.startDate"), "2024-01-05 00:00:01", false);
		// 登记时间范围（结束）
		API_DEF_ADD_QUERY_PARAMS(String, "end_date", ZH_WORDS_GETTER("query-healthcertificatelist.field.endDate"), "2024-02-05 23:59:59", false);
		// 姓名
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("query-healthcertificatelist.field.name"), "LiHua", false);
		// 姓别
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("query-healthcertificatelist.field.sex"), "male", false);
		// 年龄
		API_DEF_ADD_QUERY_PARAMS(Int32, "age", ZH_WORDS_GETTER("query-healthcertificatelist.field.age"), 18, false);
		// 打印状态
		API_DEF_ADD_QUERY_PARAMS(Int32, "print_state", ZH_WORDS_GETTER("query-healthcertificatelist.field.printState"), 0, false);
		// 上传状态
		API_DEF_ADD_QUERY_PARAMS(Int32, "is_upload", ZH_WORDS_GETTER("query-healthcertificatelist.field.isUpload"), 0, false);
	}
	ENDPOINT(API_M_GET, "/healthcertificate-manage/healthcertilist", queryHealthCertificateList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(healthCertificateList, HealthCertificateListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryHealthCertificateList(healthCertificateList, authObject->getPayload()));
	}
	// 3.2 定义测试声明式服务调用的接口1处理
private:
	HealthCertificateListPageJsonVO::Wrapper execQueryHealthCertificateList(const HealthCertificateListQuery::Wrapper& query, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif
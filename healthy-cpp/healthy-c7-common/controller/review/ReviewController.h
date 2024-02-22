#pragma once
#ifndef _REVIEWCONTROLLER_H_
#define _REVIEWCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/review/ReviewQuery.h"
#include "domain/dto/review/ReviewListDTO.h"
#include "domain/vo/review/ReviewVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 复查记录控制器，基础接口的使用
 */
class ReviewController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ReviewController);
	// 3 定义接口
public:
	// 3.1 定义分页查询复查记录接口描述
	ENDPOINT_INFO(queryReview) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("review.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ReviewListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "personName", ZH_WORDS_GETTER("review.field.personName"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("review.field.personId"), "0001", false);
		//复查项目check_project_id varchar(50)
		API_DEF_ADD_QUERY_PARAMS(String, "checkProjectId", ZH_WORDS_GETTER("review.field.checkProjectId"), "1234", false);
		API_DEF_ADD_QUERY_PARAMS(String, "checkProjectName", ZH_WORDS_GETTER("review.field.checkProjectName"), "abcd", false);
		//复查说明review_explain varchar(255)
		API_DEF_ADD_QUERY_PARAMS(String, "reviewExplain", ZH_WORDS_GETTER("review.field.reviewExplain"), "fall ill", false);
		//操作日期review_time` datetime '复查日期'
		API_DEF_ADD_QUERY_PARAMS(String, "reviewTime", ZH_WORDS_GETTER("review.field.reviewTime"), "2024-01-01", false);
		//登记日期create_time datetime '创建日期',
		API_DEF_ADD_QUERY_PARAMS(String, "createTime", ZH_WORDS_GETTER("review.field.createTime"), "2024-01-01", false);
		//登记状态state int '审核状态
		API_DEF_ADD_QUERY_PARAMS(UInt64, "state", ZH_WORDS_GETTER("review.field.state"), 1, false);
		//危害因素hazard_factor_code varchar(255)
		API_DEF_ADD_QUERY_PARAMS(String, "hazardFactorCode", ZH_WORDS_GETTER("review.field.hazardFactorCode"), "virus", false);
		//操作
		
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/review/query-review", queryReview, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ReviewQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryReview(userQuery));
	}
	
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("review.put.summary"), modifyReview, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/review", modifyReview, BODY_DTO(ReviewListDTO::Wrapper, dto), execModifyReview(dto));

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeReview) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("review.delete.summary"), StringJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("review.field.id"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/review/{id}", removeReview, PATH(String, id), execRemoveReview(id));

	// 3.1 定义Pdf接口描述
	ENDPOINT_INFO(queryPdf) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("review.pdf.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ReviewJsonVO);
		// 定义分页查询参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "personName", ZH_WORDS_GETTER("review.field.personName"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "personId", ZH_WORDS_GETTER("review.field.personId"), "0001", false);
	}
	// 3.2 定义Pdf接口处理
	ENDPOINT(API_M_GET, "/review/pdf-review", queryPdf, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(pdfQuery, ReviewQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPdf(pdfQuery));
	}

private: //定义接口执行函数
	// 3.3 分页查询数据
	ReviewListPageJsonVO::Wrapper execQueryReview(const ReviewQuery::Wrapper& query);
	// 3.3 修改数据
	StringJsonVO::Wrapper execModifyReview(const ReviewListDTO::Wrapper& dto);
	// 3.3 删除数据
	StringJsonVO::Wrapper execRemoveReview(const String& id);
	// 3.3 Pdf
	ReviewJsonVO::Wrapper execQueryPdf(const ReviewQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif //!_REVIEWCONTROLLER_H_
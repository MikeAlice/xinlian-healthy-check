#pragma once
#ifndef _DETAILCONTROLLER_H_
#define _DETAILCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/personDetail/DetailVO.h"
#include "../../domain/query/personDetail/DetailQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class DetailController : public oatpp::web::server::api::ApiController
{
    // 定义控制器访问入口
    API_ACCESS_DECLARE(DetailController);
public: // 定义接口
    // 定义分页查询单位列表接口描述
    ENDPOINT_INFO(queryDetail) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("detail.field.project"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(DetailJsonVO);
        // 定义分页查询参数描述
        // API_DEF_ADD_PAGE_PARAMS();

        // 定义其他查询参数描述
        API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("detail.field.name"), "xxx", false);
        API_DEF_ADD_QUERY_PARAMS(String, "gender", ZH_WORDS_GETTER("detail.field.gender"), "man", false);
        API_DEF_ADD_QUERY_PARAMS(UInt32, "age", ZH_WORDS_GETTER("detail.field.age"), 1, false);

    }
    // 定义分页查询单位列表接口
    ENDPOINT(API_M_GET, "/personDetail/query-detail", queryDetail, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
        // 解析查询参数为Query领域模型
        API_HANDLER_QUERY_PARAM(dq, DetailQuery, params);
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execQueryUnit(dq));
    }
private: // 定义接口执行函数
    DetailJsonVO::Wrapper execQueryUnit(const DetailQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_DETAILCONTROLLER_H_
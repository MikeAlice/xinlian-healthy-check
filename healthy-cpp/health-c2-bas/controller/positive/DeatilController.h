
#ifndef __DEATIL_CONTROLLER__
#define __DEATIL_CONTROLLER__

#include "domain/query/positive/DeatilQuery.h"
#include "domain/dto/positive/DeatilDTO.h"
#include "domain/vo/positive/DeatilVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 阳性结果控制器，获取阳性结果详细
 */
class DeatilController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	//定义控制器访问接口
	API_ACCESS_DECLARE(DeatilController);
	//  定义接口
public:

	//  定义查询接口描述
	ENDPOINT_INFO(queryDeatil) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("deatil.get.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DeatilJsonVO);
		// 定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt32, "id", ZH_WORDS_GETTER("deatil.field.id"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("deatil.field.name"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "namePinYin", ZH_WORDS_GETTER("deatil.field.namePinYin"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "degree", ZH_WORDS_GETTER("deatil.field.degree"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "positive", ZH_WORDS_GETTER("deatil.field.positive"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "section_name", ZH_WORDS_GETTER("deatil.field.section_name"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "advise", ZH_WORDS_GETTER("deatil.field.advise"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "healthKnowledge", ZH_WORDS_GETTER("deatil.field.healthKnowledge"), "N", false);
	}
	//定义阳性结果详细查询接口
	ENDPOINT(API_M_GET, "/positive/query-deatil", queryDeatil, QUERIES(QueryParams,params),API_HANDLER_AUTH_PARAME){
		//解析查询参数 
		API_HANDLER_QUERY_PARAM(dq, DeatilQuery, params);
		//呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryDeatil(dq));
	}
private:
	DeatilJsonVO::Wrapper execQueryDeatil(const DeatilQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // __DEATIL_CONTROLLER__

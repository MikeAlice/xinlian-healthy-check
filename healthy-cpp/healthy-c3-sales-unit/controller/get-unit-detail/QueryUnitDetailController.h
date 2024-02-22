#pragma once

#ifndef _QUERYUNITDETAILCONTROLLER_H_
#define _QUERYUNITDETAILCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "../../domain/vo/get-unit-detail/UnitDetailVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 获取单位详情    负责人：duxlong
 */
class QueryUnitDetailController: public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(QueryUnitDetailController);
public: // 3 定义接口
// 	// 3.1 定义接口描述
// 	// 3.2 定义接口处理
	ENDPOINT_INFO(queryUnitDetail) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("unit.get-detail.summary"), UnitDetailJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("unit.field.id"), "", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sales/unit/get-detail/{id}", queryUnitDetail, PATH(String, id), execQueryUnitDetail(id));


private: // 3.3 定义接口执行函数
	UnitDetailJsonVO::Wrapper execQueryUnitDetail(const String& id);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_QUERYUNITDETAILCONTROLLER_H_

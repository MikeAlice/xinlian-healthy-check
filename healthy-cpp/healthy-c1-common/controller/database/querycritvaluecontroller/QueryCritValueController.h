#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: stoner
 @Date: 2024/01/14

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _QUERYCRITVALUECONTROLLER_H_
#define _QUERYCRITVALUECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/vo/database/CritValueVO.h"
#include "../../../domain/query/database/CritValuePageQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class QueryCritValueController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(QueryCritValueController);
public://定义接口
	// 定义分页查询危急值接口描述
	ENDPOINT_INFO(queryCriticalValuePage) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("criticalValue.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CritValuePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		
		//// id
		//API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("criticalValue.field.id"), "0686fd1a5e1fa7aead2997d9d3568198",false);
		//// base_project_id 项目id
		//API_DEF_ADD_QUERY_PARAMS(String, "baseProjectId", ZH_WORDS_GETTER("criticalValue.field.baseProjectId"), "721ec226a004670dd85777190ef00cb6", false);
		
		//level 等级
		API_DEF_ADD_QUERY_PARAMS(String, "level", ZH_WORDS_GETTER("criticalValue.field.level"), "A",true);
		//type 类型
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("criticalValue.field.type"),"LT" ,true);
		//interval_value 区间值
		API_DEF_ADD_QUERY_PARAMS(String, "intervalValue", ZH_WORDS_GETTER("criticalValue.field.intervalValue"), "12",true);
		// allow_sex 适合性别
		API_DEF_ADD_QUERY_PARAMS(String, "allowSex", ZH_WORDS_GETTER("criticalValue.field.allowSex"), "女",false);
		// min_age 年龄最低值
		API_DEF_ADD_QUERY_PARAMS(Int64, "minAge", ZH_WORDS_GETTER("criticalValue.field.minAge"), 6,false);
		// max_age 年龄最高值
		API_DEF_ADD_QUERY_PARAMS(Int64, "maxAge", ZH_WORDS_GETTER("criticalValue.field.maxAge"), 97,false);
		//// department_id 所属部门
		//API_DEF_ADD_QUERY_PARAMS(String, "departmentId", ZH_WORDS_GETTER("criticalValue.filed.departmentId"),"40322777781112832" ,false);
		//// create_id 创建人
		//API_DEF_ADD_QUERY_PARAMS(String, "createId", ZH_WORDS_GETTER("criticalValue.field.createId"), "1567427468967677952",false);
		//// create_time 创建时间
		//API_DEF_ADD_QUERY_PARAMS(String, "createTime", ZH_WORDS_GETTER("criticalValue.field.createTime"),"2024-01-10 16:32:43" ,false);
	}
	// 定义分页查询危急值接口处理
	ENDPOINT(API_M_GET, "/database", queryCriticalValuePage, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(cvPageQuery,CritValuePageQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryCritValue(cvPageQuery));
	}

private:
	// 定义接口执行函数
	CritValuePageJsonVO::Wrapper execQueryCritValue(const CritValuePageQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_
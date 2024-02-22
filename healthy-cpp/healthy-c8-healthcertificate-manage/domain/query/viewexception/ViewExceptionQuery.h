#pragma once

#ifndef _VIEW_EXCEPTION_QUERY_
#define _VIEW_EXCEPTION_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取组合项目列表分页查询对象
 */
class ViewExceptionQuery : public PageQuery
{
	DTO_INIT(ViewExceptionQuery, PageQuery);
	// 健康证编号
	DTO_FIELD(String, health_ccertificate);
	DTO_FIELD_INFO(health_ccertificate) {
		info->description = ZH_WORDS_GETTER("view-exception.field.hcid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif
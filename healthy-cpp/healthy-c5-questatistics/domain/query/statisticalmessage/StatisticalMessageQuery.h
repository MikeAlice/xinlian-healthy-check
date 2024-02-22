#pragma once
#ifndef _STATISTICALMESSAGEQUERY_H_
#define _STATISTICALMESSAGEQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*获取统计信息
*/

class StatisticalMessageQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(StatisticalMessageQuery, DTO);
	// 体检完成率-体检状态
	API_DTO_FIELD_DEFAULT(UInt32, isPass, ZH_WORDS_GETTER("statistica.rate.isPass"));
	// 评价完成率
	//API_DTO_FIELD_DEFAULT(UInt32, evCompletionRate, ZH_WORDS_GETTER("statistica.rate.evCompletionRate"));

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
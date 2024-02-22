#pragma once

#ifndef _CRITICALMODIFYDTO_H_
#define _CRITICALMODIFYDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表数据对象实体
 */
class CriticalListDTO : public oatpp::DTO
{
	// 定义初始化
	DTO_INIT(CriticalListDTO, DTO);
	//Id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("critical.field.id"));
	//等级
	API_DTO_FIELD_DEFAULT(String, level, ZH_WORDS_GETTER("critical.field.level"));
	//类型
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("critical.field.type"));
	//区间值
	API_DTO_FIELD_DEFAULT(String, intervalValue, ZH_WORDS_GETTER("critical.field.intervalValue"));
	//适合性别
	API_DTO_FIELD_DEFAULT(String, allowSex, ZH_WORDS_GETTER("critical.field.allowSex"));
	//年龄最低值
	API_DTO_FIELD_DEFAULT(UInt32, minAge, ZH_WORDS_GETTER("critical.field.minAge"));
	//年龄最高值
	API_DTO_FIELD_DEFAULT(UInt32, maxAge, ZH_WORDS_GETTER("critical.field.maxAge"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
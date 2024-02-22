#pragma once
#pragma once

#ifndef _CRITICALDELETEDTO_H_
#define _CRITICALDELETEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表数据对象实体
 */
class CriticalDeleteListDTO : public oatpp::DTO
{
	// 定义初始化
	DTO_INIT(CriticalDeleteListDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("critical.field.id"));


};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
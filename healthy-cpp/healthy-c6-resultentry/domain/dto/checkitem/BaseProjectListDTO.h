#pragma once

#ifndef _BASEPROJECTLISTDTO_H_
#define _BASEPROJECTLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个基础项目体检结果的数据传输模型
 */
class BaseProjectListDTO : public oatpp::DTO
{
	DTO_INIT(BaseProjectListDTO, DTO);
	//项目代码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("checkitem.base.code"));
	//体检项目
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("checkitem.base.name"));
	//单位
	API_DTO_FIELD_DEFAULT(String, unit_name, ZH_WORDS_GETTER("checkitem.base.unit_name"));
	//参考值
	API_DTO_FIELD_DEFAULT(String, healthy_value, ZH_WORDS_GETTER("checkitem.base.healthy_value"));
	//默认值
	API_DTO_FIELD_DEFAULT(String, default_value, ZH_WORDS_GETTER("checkitem.base.default_value"));
	//明细结果类型
	API_DTO_FIELD_DEFAULT(String, result_type, ZH_WORDS_GETTER("checkiten.base.result_type"));


};

class BaseProjectPageDTO : public PageDTO<BaseProjectListDTO::Wrapper> {
	DTO_INIT(BaseProjectPageDTO, PageDTO<BaseProjectListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BASEPROJECTLISTDTO_H_


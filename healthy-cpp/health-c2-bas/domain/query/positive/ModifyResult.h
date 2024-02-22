#ifndef _MODIFYRESULT_H_
#define _MODIFYRESULT_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 修改阳性结果
*/

class ModifyResult : public oatpp::DTO
{
    DTO_INIT(ModifyResult, DTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("modify.field.id");
	}
	
	// 名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("deatil.field.name"));
	// 简拼
	API_DTO_FIELD_DEFAULT(String, namePinYin, ZH_WORDS_GETTER("deatil.field.namePinYin"));
	// 是否严重
	API_DTO_FIELD_DEFAULT(String, degree, ZH_WORDS_GETTER("deatil.field.degree"));
	//是否阳性
	API_DTO_FIELD_DEFAULT(String, positive, ZH_WORDS_GETTER("deatil.field.positive"));
	//科室
	API_DTO_FIELD_DEFAULT(String, sectionName, ZH_WORDS_GETTER("deatil.field.sectionName"));
	//职业建议
	API_DTO_FIELD_DEFAULT(String, advise, ZH_WORDS_GETTER("deatil.field.advise"));
	//健康建议
	API_DTO_FIELD_DEFAULT(String, healthKnowledge, ZH_WORDS_GETTER("deatil.field.healthKnowledge"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // _MODIFYRESULT_H_

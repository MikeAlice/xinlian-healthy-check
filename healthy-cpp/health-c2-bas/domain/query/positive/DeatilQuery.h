#ifndef __DEATIL_QUERY__
#define __DEATIL_QUERY__

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 查询阳性结果详细实体
 */
class DeatilQuery : public oatpp::DTO
{
	DTO_INIT(DeatilQuery, DTO);
	//查询类型
	API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("deatil.field.type"));
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
#endif // !__DEATIL_QUERY__
#ifndef _SAMPLEBARCODESVIEW_QUERY_
#define	_SAMPLEBARCODESVIEW_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 查询样本条码
*/
class SampleBarcodesViewQuery :public oatpp::DTO
{
	DTO_INIT(SampleBarcodesViewQuery, DTO);
	//体检人ID
	DTO_FIELD(String, person_id);
	DTO_FIELD_INFO(person_id) {
		info->description = ZH_WORDS_GETTER("samplebarcodesview.file.personid");
	}
	//分组项目ID
	DTO_FIELD(List<String>, group_item_id);
	DTO_FIELD_INFO(group_item_id) {
		info->description = ZH_WORDS_GETTER("samplebarcodesview.file.groupitemid");
	}
	//条码类型
	DTO_FIELD(UInt64, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("samplebarcodesview.file.type");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLEBARCODESVIEW_QUERY_


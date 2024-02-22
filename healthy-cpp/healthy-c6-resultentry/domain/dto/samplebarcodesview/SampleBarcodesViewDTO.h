#ifndef _SAMPLEBARCODESVIEW_DTO_
#define _SAMPLEBARCODESVIEW_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 样本条码传输对象
*/
class SampleBarcodesViewDTO :public oatpp::DTO
{
	DTO_INIT(SampleBarcodesViewDTO, DTO);
	//条形码内容
	DTO_FIELD(String, barcode);
	DTO_FIELD_INFO(barcode) {
		info->description = ZH_WORDS_GETTER("samplebarcodesview.file.barcode");
	}
	//体检编号
	DTO_FIELD(String, test_num);
	DTO_FIELD_INFO(test_num) {
		info->description = ZH_WORDS_GETTER("samplebarcodesview.file.test_num");
	}
	//体检人员名字
	DTO_FIELD(String, person_name);
	DTO_FIELD_INFO(person_name) {
		info->description = ZH_WORDS_GETTER("samplebarcodesview.file.person_name");
	}
	//体检人员年龄
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("samplebarcodesview.file.age");
	}
	//体检人员性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("samplebarcodesview.file.sex");
	}
	//分组项目名称
	DTO_FIELD(String, group_item_name);
	DTO_FIELD_INFO(group_item_name) {
		info->description = ZH_WORDS_GETTER("samplebarcodesview.file.group_item_name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLEBARCODESVIEW_DTO_

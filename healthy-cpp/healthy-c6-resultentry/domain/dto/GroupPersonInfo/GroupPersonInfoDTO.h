#pragma once
#ifndef _GROUP_PERSON_INFO_DTO_
#define _GROUP_PERSON_INFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 人员详情传输数据对象实体
 */
class GroupPersonInfoDTO : public oatpp::DTO
{
	DTO_INIT(GroupPersonInfoDTO, DTO);

	//是否通过检查
	API_DTO_FIELD_DEFAULT(UInt32, is_pass, ZH_WORDS_GETTER("group_person.data.is_pass"));

	// 体检编号
	API_DTO_FIELD_DEFAULT(String, test_num, ZH_WORDS_GETTER("group_person.data.test_num"));

	// 身份证号
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("group_person.data.id_card"));
	
	// 姓名
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("group_person.data.name"));

	// 性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("group_person.data.sex"));

	// 年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("group_person.data.age"));
	
	// 体检类型
	API_DTO_FIELD_DEFAULT(String, physical_type, ZH_WORDS_GETTER("group_person.data.physical_type"));
	
	// 订单类型
	API_DTO_FIELD_DEFAULT(UInt32, sporadic_physical, ZH_WORDS_GETTER("group_person.data.sporadic_physical"));

	// 单位名称
	API_DTO_FIELD_DEFAULT(String, dept, ZH_WORDS_GETTER("group_person.data.dept"));
	
	// 登记时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("group_person.data.create_time"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_PERSON_INFO_DTO_
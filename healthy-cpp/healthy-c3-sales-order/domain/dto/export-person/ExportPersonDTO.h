#pragma once

#ifndef _ORDEROUTPUT_DTO_
#define _ORDEROUTPUT_DTO_
#include"../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class ExportPersonDTO :public oatpp::DTO {
	DTO_INIT(ExportPersonDTO,DTO);
	//主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("person.field.id"));
	//人员姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("person.field.person_name"));
	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("person.field.sex"));
	//证件号码
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("person.field.id_card"));
	//年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("person.field.age"));
	//分组
	API_DTO_FIELD_DEFAULT(String, groupName, ZH_WORDS_GETTER("person.field.group_name"));
	//手机号码
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("person.field.mobile"));
	//其他危害因素名称
	API_DTO_FIELD_DEFAULT(String, otherHazardFactors, ZH_WORDS_GETTER("person.field.other_hazard_factors"));
	//工种名称
	API_DTO_FIELD_DEFAULT(String, workTypeText, ZH_WORDS_GETTER("person.field.work_type_text"));
	//其他工种名称
	API_DTO_FIELD_DEFAULT(String, workName, ZH_WORDS_GETTER("person.field.work_name"));
	//在岗状态
	API_DTO_FIELD_DEFAULT(String, workStateText, ZH_WORDS_GETTER("person.field.work_state_text"));
	//所属部门
	API_DTO_FIELD_DEFAULT(String, department, ZH_WORDS_GETTER("person.field.department"));
	//体检类型
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("person.field.physical_type"));
	//是否通过检查(0-未登记, 1-登记, 2-在检, 3-总检, 4-已完成)
	API_DTO_FIELD_DEFAULT(Int32, isPass, ZH_WORDS_GETTER("person.field.is_pass"));
};

#include OATPP_CODEGEN_END(DTO)
#endif
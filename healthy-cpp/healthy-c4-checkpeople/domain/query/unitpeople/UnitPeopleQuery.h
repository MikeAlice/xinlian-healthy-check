#pragma once
#ifndef _UNIT_PEOPLE_QUERY_
#define _UNIT_PEOPLE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 订单人员单条详细信息查询对象
 */
class UnitPeopleQuery : public PageQuery
{
	DTO_INIT(UnitPeopleQuery, PageQuery);
	// 订单号
	DTO_FIELD(String, orderId);
	DTO_FIELD_INFO(orderId) {
		info->description = ZH_WORDS_GETTER("unit.field.orderId");
	}

	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("unit.field.idCard"));
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("unit.field.idCard"));
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("unit.field.idCard"));
	API_DTO_FIELD_DEFAULT(String, birth, ZH_WORDS_GETTER("unit.field.idCard"));
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("unit.field.idCard"));
	API_DTO_FIELD_DEFAULT(String, is_marry, ZH_WORDS_GETTER("unit.field.idCard"));
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("unit.field.idCard"));

	//// 查询人员证件号
	//DTO_FIELD(String, id_card);
	//DTO_FIELD_INFO(id_card) {
	//	info->description = ZH_WORDS_GETTER("unit.field.idCard");
	//}
	//DTO_FIELD(String, person_name);
	//DTO_FIELD_INFO(person_name) {
	//	info->description = ZH_WORDS_GETTER("unit.field.personName");
	//}
	//DTO_FIELD(String, sex);
	//DTO_FIELD_INFO(sex) {
	//	info->description = ZH_WORDS_GETTER("unit.field.Sex");
	//}
	//DTO_FIELD(String, birth);
	//DTO_FIELD_INFO(birth) {
	//	info->description = ZH_WORDS_GETTER("unit.field.Birth ");
	//}
	//DTO_FIELD(String, age);
	//DTO_FIELD_INFO(age) {
	//	info->description = ZH_WORDS_GETTER("unit.field.Age");
	//}
	//DTO_FIELD(String, is_marry);
	//DTO_FIELD_INFO(is_marry) {
	//	info->description = ZH_WORDS_GETTER("unit.field.isMarry");
	//}
	//DTO_FIELD(String, mobile);
	//DTO_FIELD_INFO(mobile) {
	//	info->description = ZH_WORDS_GETTER("unit.field.mobile");
	//}


};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UNIT_PEOPLE_QUERY_
#pragma once

#ifndef _UNITLISTDTO_H_
#define _UNITLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 单位列表传输数据对象实体
 */
class UnitListDTO : public oatpp::DTO
{
	DTO_INIT(UnitListDTO, DTO);
	//单位ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unit.field.id"));
	//单位名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unit.field.name"));
	//体检类型
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unit.field.physical_type"));
	//统一社会信用代码
	API_DTO_FIELD_DEFAULT(String, uscc, ZH_WORDS_GETTER("unit.field.uscc"));
	//行业类型名称
	API_DTO_FIELD_DEFAULT(String, industryName, ZH_WORDS_GETTER("unit.field.industry_name"));
	//所属地区地址
	API_DTO_FIELD_DEFAULT(String, regionName, ZH_WORDS_GETTER("unit.field.region_name"));
	//经济类型名称
	API_DTO_FIELD_DEFAULT(String, economicTypeName, ZH_WORDS_GETTER("unit.field.economic_type_name"));
	//企业规模名称
	API_DTO_FIELD_DEFAULT(String, businessScaleName, ZH_WORDS_GETTER("unit.field.business_scale_name"));
	//体检联系人
	API_DTO_FIELD_DEFAULT(String, linkMan2, ZH_WORDS_GETTER("unit.field.link_man2"));
	//体检联系人电话
	API_DTO_FIELD_DEFAULT(String, linkPhone2, ZH_WORDS_GETTER("unit.field.link_phone2"));
};

/**
 * 单位列表分页数据实体
 */
class UnitListPageDTO : public PageDTO<UnitListDTO::Wrapper> {
	DTO_INIT(UnitListPageDTO, PageDTO<UnitListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITLISTDTO_H_
#pragma once

#ifndef _UNITDETAILDTO_H_
#define _UNITDETAILDTO_H_

#include "../../GlobalInclude.h"
#include "TestDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 前端→后端 传输对象：单位详情 
*/
class UnitDetailDTO : public oatpp::DTO
{
	DTO_INIT(UnitDetailDTO, DTO);

	// 基础信息
	//单位ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unit.field.id"));
	//单位名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unit.field.name"));
	//体检类型
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unit.field.physical_type"));
	//统一社会信用代码
	API_DTO_FIELD_DEFAULT(String, uscc, ZH_WORDS_GETTER("unit.field.uscc"));
	//行业类型编码
	API_DTO_FIELD_DEFAULT(String, industryCode, ZH_WORDS_GETTER("unit.field.industry_code"));
	//行业类型名称
	API_DTO_FIELD_DEFAULT(String, industryName, ZH_WORDS_GETTER("unit.field.industry_name"));
	//所属地区编码
	API_DTO_FIELD_DEFAULT(String, regionCode, ZH_WORDS_GETTER("unit.field.region_code"));
	//所属地区地址
	API_DTO_FIELD_DEFAULT(String, regionName, ZH_WORDS_GETTER("unit.field.region_name"));
	//经济类型编码
	API_DTO_FIELD_DEFAULT(String, economicTypeCode, ZH_WORDS_GETTER("unit.field.economic_type_code"));
	//经济类型名称
	API_DTO_FIELD_DEFAULT(String, economicTypeName, ZH_WORDS_GETTER("unit.field.economic_type_name"));
	//单位注册地址
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("unit.field.address"));
	//企业规模编码
	API_DTO_FIELD_DEFAULT(String, businessScaleCode, ZH_WORDS_GETTER("unit.field.business_scale_code"));
	//企业规模名称
	API_DTO_FIELD_DEFAULT(String, businessScaleName, ZH_WORDS_GETTER("unit.field.business_scale_name"));
	//职工人数
	API_DTO_FIELD_DEFAULT(UInt32, employeesNum, ZH_WORDS_GETTER("unit.field.employees_num"));
	//接触职业病危害因素人数
	API_DTO_FIELD_DEFAULT(UInt32, dangerNum, ZH_WORDS_GETTER("unit.field.danger_num"));
	//体检联系人
	API_DTO_FIELD_DEFAULT(String, linkMan2, ZH_WORDS_GETTER("unit.field.link_man2"));
	//体检联系人电话
	API_DTO_FIELD_DEFAULT(String, linkPhone2, ZH_WORDS_GETTER("unit.field.link_phone2"));
	//附件文件名称（营业执照）
	API_DTO_FIELD_DEFAULT(String, attachment, ZH_WORDS_GETTER("unit.field.attachment"));

	// 其他信息
	//法人姓名
	API_DTO_FIELD_DEFAULT(String, legalPerson, ZH_WORDS_GETTER("unit.field.legal_person"));
	//法人电话
	API_DTO_FIELD_DEFAULT(String, legalPhone, ZH_WORDS_GETTER("unit.field.legal_phone"));
	//生产工人数
	API_DTO_FIELD_DEFAULT(UInt32, workmanNum, ZH_WORDS_GETTER("unit.field.workman_num"));
	//接触职业病危害因素女工人数
	API_DTO_FIELD_DEFAULT(UInt32, workmistressNum, ZH_WORDS_GETTER("unit.field.workmistress_num"));
	//单位注册邮编
	API_DTO_FIELD_DEFAULT(String, postalCode, ZH_WORDS_GETTER("unit.field.postal_code"));
	//经营面积
	API_DTO_FIELD_DEFAULT(String, workArea, ZH_WORDS_GETTER("unit.field.work_area"));
	//注册资金
	API_DTO_FIELD_DEFAULT(String, regCapital, ZH_WORDS_GETTER("unit.field.reg_capital"));
	//职业卫生安全负责人
	API_DTO_FIELD_DEFAULT(String, safetyPrincipal, ZH_WORDS_GETTER("unit.field.safety_principal"));
	//建档日期
	API_DTO_FIELD_DEFAULT(String, filingDate, ZH_WORDS_GETTER("unit.field.filing_date"));
	//建厂日期
	API_DTO_FIELD_DEFAULT(String, establishmentDate, ZH_WORDS_GETTER("unit.field.establishment_date"));
	//检测联系人
	API_DTO_FIELD_DEFAULT(String, linkMan1, ZH_WORDS_GETTER("unit.field.link_man1"));
	//检测联系电话
	API_DTO_FIELD_DEFAULT(String, linkPhone1, ZH_WORDS_GETTER("unit.field.link_phone1"));
	//检测联系人职务
	API_DTO_FIELD_DEFAULT(String, position1, ZH_WORDS_GETTER("unit.field.position1"));
	//体检联系人职务
	API_DTO_FIELD_DEFAULT(String, position2, ZH_WORDS_GETTER("unit.field.position2"));
	//安全联系人职务
	API_DTO_FIELD_DEFAULT(String, safePosition, ZH_WORDS_GETTER("unit.field.safe_position"));
	//安全联系人电话
	API_DTO_FIELD_DEFAULT(String, safePhone, ZH_WORDS_GETTER("unit.field.safe_phone"));
	//隶属关系
	API_DTO_FIELD_DEFAULT(String, subjeConn, ZH_WORDS_GETTER("unit.field.subje_conn"));
	//作业场所地址
	API_DTO_FIELD_DEFAULT(String, enrolAddress, ZH_WORDS_GETTER("unit.field.enrol_address"));
	//作业场所邮编
	API_DTO_FIELD_DEFAULT(String, enrolPostalCode, ZH_WORDS_GETTER("unit.field.enrol_postal_code"));
	//职业卫生管理机构
	API_DTO_FIELD_DEFAULT(String, occManaOffice, ZH_WORDS_GETTER("unit.field.occ_mana_office"));

	// 检测信息
	API_DTO_FIELD_DEFAULT(List<TestDetailDTO::Wrapper>, test, ZH_WORDS_GETTER("unit.field.test"));

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITDETAILDTO_H_
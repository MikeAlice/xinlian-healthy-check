#pragma once

#ifndef _UNITDETAILDO_H_
#define _UNITDETAILDO_H_

#include "../DoInclude.h"

class UnitDetailDO
{
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, name, Name);
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	CC_SYNTHESIZE(string, uscc, Uscc);
	CC_SYNTHESIZE(string, industryCode, IndustryCode);
	CC_SYNTHESIZE(string, industryName, IndustryName);
	CC_SYNTHESIZE(string, regionCode, RegionCode);
	CC_SYNTHESIZE(string, regionName, RegionName);
	CC_SYNTHESIZE(string, economicTypeCode, EconomicTypeCode);
	CC_SYNTHESIZE(string, economicTypeName, EconomicTypeName);
	CC_SYNTHESIZE(string, address, Address);
	CC_SYNTHESIZE(string, businessScaleCode, BusinessScaleCode);
	CC_SYNTHESIZE(string, businessScaleName, BusinessScaleName);
	CC_SYNTHESIZE(uint32_t, employeesNum, EmployeesNum);
	CC_SYNTHESIZE(uint32_t, dangerNum, DangerNum);
	CC_SYNTHESIZE(string, linkMan2, LinkMan2);
	CC_SYNTHESIZE(string, linkPhone2, LinkPhone2);
	CC_SYNTHESIZE(string, attachment, Attachment);
	CC_SYNTHESIZE(string, legalPerson, LegalPerson);
	CC_SYNTHESIZE(string, legalPhone, LegalPhone);
	CC_SYNTHESIZE(uint32_t, workmanNum, WorkmanNum);
	CC_SYNTHESIZE(uint32_t, workmistressNum, WorkmistressNum);
	CC_SYNTHESIZE(string, postalCode, PostalCode);
	CC_SYNTHESIZE(string, workArea, WorkArea);
	CC_SYNTHESIZE(string, regCapital, RegCapital);
	CC_SYNTHESIZE(string, safetyPrincipal, SafetyPrincipal);
	CC_SYNTHESIZE(string, filingDate, FilingDate);
	CC_SYNTHESIZE(string, establishmentDate, EstablishmentDate);
	CC_SYNTHESIZE(string, linkMan1, LinkMan1);
	CC_SYNTHESIZE(string, linkPhone1, LinkPhone1);
	CC_SYNTHESIZE(string, position1, Position1);
	CC_SYNTHESIZE(string, position2, Position2);
	CC_SYNTHESIZE(string, safePosition, SafePosition);
	CC_SYNTHESIZE(string, safePhone, SafePhone);
	CC_SYNTHESIZE(string, subjeConn, SubjeConn);
	CC_SYNTHESIZE(string, enrolAddress, EnrolAddress);
	CC_SYNTHESIZE(string, enrolPostalCode, EnrolPostalCode);
	CC_SYNTHESIZE(string, occManaOffice, OccManaOffice);
	CC_SYNTHESIZE(uint32_t, delFlag, DelFlag);
	CC_SYNTHESIZE(string, createId, CreateId);
	CC_SYNTHESIZE(string, createTime, CreateTime);
	CC_SYNTHESIZE(string, updateId, UpdateId);
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	CC_SYNTHESIZE(string, deleteId, DeleteId);
	CC_SYNTHESIZE(string, deleteTime, DeleteTime);
public:
	UnitDetailDO():id(""), name(""), physicalType(""), uscc(""), industryCode(""), industryName(""), 
		regionCode(""), regionName(""), economicTypeCode(""), economicTypeName(""), address(""), 
		businessScaleCode(""), businessScaleName(""), employeesNum(0), dangerNum(0), linkMan2(""), linkPhone2(""), 
		attachment(""), legalPerson(""), legalPhone(""), workmanNum(0), workmistressNum(0), postalCode(""), 
		workArea(""), regCapital(""), safetyPrincipal(""), filingDate(""), establishmentDate(""), 
		linkMan1(""), linkPhone1(""), position1(""), position2(""), safePosition(""), safePhone(""), 
		subjeConn(""), enrolAddress(""), enrolPostalCode(""), occManaOffice(""), delFlag(0), 
		createId(""), createTime(""), updateId(""), updateTime(""), deleteId(""), deleteTime("")
	{	}
};

#endif // !_UNITDETAILDO_H_
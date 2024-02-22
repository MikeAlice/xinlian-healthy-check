#include "stdafx.h"
#include "ModifyUnitService.h"
#include "../../domain/do/update-unit/UnitDetailDO.h"
#include "../../domain/do/update-unit/TestDetailDO.h"
#include <list>
#include "../../dao/update-unit/ModifyUnitDAO.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include <string>
#include "../../domain/dto/update-unit/TestDetailDTO.h"
//#include "uselib/snowflake/TestSnowflake.h"
std::string ModifyUnitService::updateUnit(const UnitDetailDTO::Wrapper& unitDTO, const string& updateId)
{
	// ��װDO����
	UnitDetailDO unitDO;
	TestDetailDO testDO;
	std::string delTestId;
	std::list<TestDetailDO> testListDO;
	string formatTime = SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S");
//	auto idGen = IDGenerater<NonLockType>::GetInstance(1, 1);
	//������Ϣ
	ZO_STAR_DOMAIN_DTO_TO_DO(unitDO, unitDTO, Id, id, Name, name, PhysicalType, physicalType,
		Uscc, uscc, IndustryCode, industryCode, IndustryName, industryName, RegionCode, regionCode,
		RegionName, regionName, EconomicTypeCode, economicTypeCode, EconomicTypeName, economicTypeName,
		Address, address, BusinessScaleCode, businessScaleCode, BusinessScaleName, businessScaleName,
		EmployeesNum, employeesNum, DangerNum, dangerNum, LinkMan2, linkMan2, LinkPhone2, linkPhone2,
		Attachment, attachment);
	//������Ϣ
	ZO_STAR_DOMAIN_DTO_TO_DO(unitDO, unitDTO, LegalPerson, legalPerson, LegalPhone, legalPhone, 
		WorkmanNum, workmanNum, WorkmistressNum, workmistressNum, PostalCode, postalCode, 
		WorkArea, workArea, RegCapital, regCapital, SafetyPrincipal, safetyPrincipal, 
		FilingDate, filingDate, EstablishmentDate, establishmentDate, LinkMan1, linkMan1, 
		LinkPhone1, linkPhone1, Position1, position1, Position2, position2, SafePosition, safePosition, 
		SafePhone, safePhone, SubjeConn, subjeConn, EnrolAddress, enrolAddress, EnrolPostalCode, enrolPostalCode, 
		OccManaOffice, occManaOffice);
	//������¼
	unitDO.setUpdateId(updateId);
	unitDO.setUpdateTime(formatTime);
	//�����Ϣ
	if(!unitDTO->test->empty())
	{
		for (auto testDTO = unitDTO->test->begin(); testDTO != unitDTO->test->end(); ++testDTO)
		{
//			std::cout << "unitDTO->test->begin()+i:" << (*testDTO)->id.getValue({}) << "   " << (*testDTO)->unitId.getValue({}) << std::endl;
			//(*testDTO)->id
			ZO_STAR_DOMAIN_DTO_TO_DO(testDO, (*testDTO), Id, id, UnitId, unitId, HazardFactors, hazardFactors,
				HazardFactorsText, hazardFactorsText, OtherHazardFactors, otherHazardFactors, WorkStateCode, workStateCode,
				WorkStateText, workStateText, WorkTypeCode, workTypeCode, WorkTypeText, workTypeText, WorkName, workName,
				Strength, strength, TestTime, testTime);
			if (!testDO.getId().empty()) {
				if (testDTO != unitDTO->test->begin())
				{
					delTestId += "','";
				}
				delTestId += testDO.getId();
				//������¼
				testDO.setUpdateId(updateId);
				testDO.setUpdateTime(formatTime);
			}
			else
			{
				//testDO.setId(idGen->NextID());
				//������¼
				testDO.setCreateId(updateId);
				testDO.setCreateTime(formatTime);
				testDO.setDelFlag(0);
			}
			testListDO.push_back(testDO);
		}
// 		if (!delTestId.empty())
// 		{
// 			delTestId += "'";
// 			delTestId.insert(0, "'");
// 		}
	}
//	std::cout << "testListDO:" << testListDO.size() << std::endl;

	// ִ�е�λ�����޸�
	ModifyUnitDAO dao;
	if(!dao.updateUnit(unitDO))
		return "update unit fail";
	//ִ�м������ɾ��
	if(!delTestId.empty())
	{
		if (!dao.deleteTest(delTestId, unitDO.getId(), updateId, formatTime))
			return "delete test fail";
	}
	//ִ�м�������޸�
	if(!unitDTO->test->empty())
	{
		if (!dao.updateTest(testListDO))
			return "update test fail";
	}

	return "success";
}

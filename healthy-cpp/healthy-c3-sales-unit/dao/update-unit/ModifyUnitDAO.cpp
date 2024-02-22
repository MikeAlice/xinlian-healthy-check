#include "stdafx.h"
#include "ModifyUnitDAO.h"
#include "uselib/snowflake/TestSnowflake.h"

int ModifyUnitDAO::updateUnit(const UnitDetailDO& unitDO)
{
	int flag = 1;
	string sql = "UPDATE `t_group_unit` SET `id`=?,`name`=?,`physical_type`=?,`uscc`=?,"
		"`industry_code`=?,`industry_name`=?,`region_code`=?,`region_name`=?,"
		"`economic_type_code`=?,`economic_type_name`=?,`address`=?,"
		"`business_scale_code`=?,`business_scale_name`=?,`employees_num`=?,`danger_num`=?,"
		"`link_man2`=?,`link_phone2`=?,`attachment`=?,`legal_person`=?,`legal_phone`=?,"
		"`workman_num`=?,`workmistress_num`=?,`postal_code`=?,`work_area`=?,`reg_capital`=?,"
		"`safety_principal`=?,`link_man1`=?,`link_phone1`=?,"
		"`position1`=?,`position2`=?,`safe_position`=?,`safe_phone`=?,`subje_conn`=?,"
		"`enrol_address`=?,`enrol_postal_code`=?,`occ_mana_office`=?,`update_id`=?,`update_time`=?"
		" WHERE `id`=?";
	flag= sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%i%i%s%s%s%s%s%i%i%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		unitDO.getId(), unitDO.getName(), unitDO.getPhysicalType(), unitDO.getUscc(), 
		unitDO.getIndustryCode(), unitDO.getIndustryName(), unitDO.getRegionCode(), unitDO.getRegionName(), 
		unitDO.getEconomicTypeCode(), unitDO.getEconomicTypeName(), unitDO.getAddress(), 
		unitDO.getBusinessScaleCode(), unitDO.getBusinessScaleName(), unitDO.getEmployeesNum(), 
		unitDO.getDangerNum(), unitDO.getLinkMan2(), unitDO.getLinkPhone2(), unitDO.getAttachment(), 
		unitDO.getLegalPerson(), unitDO.getLegalPhone(), unitDO.getWorkmanNum(), unitDO.getWorkmistressNum(), 
		unitDO.getPostalCode(), unitDO.getWorkArea(), unitDO.getRegCapital(), unitDO.getSafetyPrincipal(), 
		 unitDO.getLinkMan1(), unitDO.getLinkPhone1(), 
		unitDO.getPosition1(), unitDO.getPosition2(), unitDO.getSafePosition(), unitDO.getSafePhone(), 
		unitDO.getSubjeConn(), unitDO.getEnrolAddress(), unitDO.getEnrolPostalCode(), unitDO.getOccManaOffice(), 
		unitDO.getUpdateId(), unitDO.getUpdateTime(), unitDO.getId());
	if (!flag) return flag;

	if (!unitDO.getEstablishmentDate().empty())
	{
		sql = "UPDATE `t_group_unit` SET `establishment_date`= ? WHERE `id`= ? ";
		flag= sqlSession->executeUpdate(sql, "%s%s", unitDO.getEstablishmentDate(), unitDO.getId());
		if (!flag) return flag;
	}

	if (!unitDO.getFilingDate().empty())
	{
		sql = "UPDATE `t_group_unit` SET `filing_date`= ? WHERE `id`= ? ";
		flag = sqlSession->executeUpdate(sql, "%s%s", unitDO.getFilingDate(), unitDO.getId());
		if (!flag) return flag;
	}

	return flag;
}

int ModifyUnitDAO::deleteTest(const std::string delTestId, const std::string unitId, const std::string deleteId, const std::string deleteTime)
{
	string sql = "UPDATE `t_test_record` set `del_flag`=1,`delete_id`=? , `delete_time`=? WHERE `unit_id`= ? AND `id` NOT IN(? )";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", deleteId, deleteTime,unitId, delTestId);
}

int ModifyUnitDAO::updateTest(std::list<TestDetailDO>& testListDO)
{
	std::cout << "DAO:\ntestListDO:" << testListDO.size() << std::endl;
	int flag = 1;
	auto idGen = IDGenerater<NonLockType>::GetInstance(1, 1);
	//for(auto testDO = testListDO.begin(); testDO != testListDO.end(); ++testDO)
	for (auto& testDO : testListDO)
	{
// 		std::cout << "testListDObegin()+i:" << testDO.getId() << "   " << testDO.getUnitId() << std::endl;
// 		std::cout << "testDO.getId():'"<<testDO.getId() <<"'" << std::endl;
		
		if (testDO.getId().empty())
		{
			testDO.setId(idGen->NextID());
// 			std::cout << "testDO.getId():'" << testDO.getId() << "'" << std::endl;
			string sql = "INSERT INTO `t_test_record` (`id`,`unit_id`,`hazard_factors`,`hazard_factors_text`,"
				"`other_hazard_factors`,`work_state_code`,`work_state_text`,`work_type_code`,`work_type_text`,"
				"`work_name`,`strength`,`del_flag`,`create_id`,`create_time`)  VALUES "
				"(?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
			flag= sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%i%s%s", testDO.getId(), testDO.getUnitId(), 
				testDO.getHazardFactors(), testDO.getHazardFactorsText(), testDO.getOtherHazardFactors(), 
				testDO.getWorkStateCode(), testDO.getWorkStateText(), testDO.getWorkTypeCode(), testDO.getWorkTypeText(), 
				testDO.getWorkName(), testDO.getStrength(), testDO.getDelFlag(), 
				testDO.getCreateId(), testDO.getCreateTime());
			if (!flag) return flag;

			if (!testDO.getTestTime().empty())
			{
				sql = "UPDATE `t_test_record` SET `test_time`= ? WHERE `id`= ? ";
				flag = sqlSession->executeUpdate(sql, "%s%s", testDO.getTestTime(), testDO.getId());
				if (!flag) return flag;
			}
		}
		else
		{
			string sql = "UPDATE `t_test_record` SET `unit_id`=?, `hazard_factors`=?, `hazard_factors_text`=?, "
				"`other_hazard_factors`=?, `work_state_code`=?, `work_state_text`=?, `work_type_code`=?, `work_type_text`=?, "
				"`work_name`=?, `strength`=?, `update_id`=?, `update_time`=? WHERE `id`=?";
			flag= sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s", testDO.getUnitId(),
				testDO.getHazardFactors(), testDO.getHazardFactorsText(), testDO.getOtherHazardFactors(),
				testDO.getWorkStateCode(), testDO.getWorkStateText(), testDO.getWorkTypeCode(), testDO.getWorkTypeText(),
				testDO.getWorkName(), testDO.getStrength(),  
				testDO.getUpdateId(), testDO.getUpdateTime(), testDO.getId());
			if (!flag) return flag;

			if (!testDO.getTestTime().empty())
			{
				sql = "UPDATE `t_test_record` SET `test_time`= ? WHERE `id`= ? ";
				flag = sqlSession->executeUpdate(sql, "%s%s", testDO.getTestTime(), testDO.getId());
				if (!flag) return flag;
			}
		}
	}
	return flag;
}

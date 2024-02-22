#pragma once
#ifndef _UNITPHYSICALEXAMINATIONORDERS_MAPPER_
#define _UNITPHYSICALEXAMINATIONORDERS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/ReportStatistics/ReportStatisticsDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PhysicalExaminationPersonnelMapper : public Mapper<PhysicalExaminationPersonnelDO>
{
public:
	PhysicalExaminationPersonnelDO mapper(ResultSet* resultSet) const override
	{
		PhysicalExaminationPersonnelDO data;
		data.setId(resultSet->getString(1));
		data.setPersonName(resultSet->getString(2));
		data.setMobile(resultSet->getString(3));
		data.setSex(resultSet->getString(4));
		data.setAge(resultSet->getInt(5));
		data.setIdCard(resultSet->getString(6));
		data.setDepartment(resultSet->getString(7));
		data.setPhysicalDate(resultSet->getString(8));
		data.setPhysicalType(resultSet->getString(9));
		data.setCheckRusult(resultSet->getInt(10));
		data.setConcludingObservations(resultSet->getString(11));
		return data;
	}
};

class ReviewPersonnelMapper : public Mapper<ReviewPersonnelDO>
{
public:
	ReviewPersonnelDO mapper(ResultSet* resultSet) const override
	{
		ReviewPersonnelDO data;
		data.setId(resultSet->getString(1));
		data.setPersonName(resultSet->getString(2));
		data.setMobile(resultSet->getString(3));
		data.setSex(resultSet->getString(4));
		data.setAge(resultSet->getInt(5));
		data.setIdCard(resultSet->getString(6));
		data.setPhysicalDate(resultSet->getString(7));
		data.setPhysicalType(resultSet->getString(8));
		data.setReason(resultSet->getString(9));
		data.setCheckProjectName(resultSet->getString(10));
		return data;
	}
};

class ReviewResultsMapper : public Mapper<ReviewResultsDO>
{
public:
	ReviewResultsDO mapper(ResultSet* resultSet) const override
	{
		ReviewResultsDO data;
		data.setId(resultSet->getString(1));
		data.setPersonName(resultSet->getString(2));
		data.setMobile(resultSet->getString(3));
		data.setSex(resultSet->getString(4));
		data.setAge(resultSet->getInt(5));
		data.setIdCard(resultSet->getString(6));
		data.setHazardFactorCode(resultSet->getString(7));
		data.setWorkTypeText(resultSet->getString(8));
		data.setExposureToHarmfulWorkExperience(resultSet->getInt(9));
		data.setPhysicalDate(resultSet->getString(10));
		data.setPhysicalType(resultSet->getString(11));
		data.setCheckRusult(resultSet->getString(12));
		data.setConcludingObservations(resultSet->getString(13));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_
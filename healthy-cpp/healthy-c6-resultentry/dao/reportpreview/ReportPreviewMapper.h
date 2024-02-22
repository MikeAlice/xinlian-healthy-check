#ifndef _REPORTPREVIEW_MAPPER_
#define _REPORTPREVIEW_MAPPER_
#include "Mapper.h"
#include"domain/do/reportpreview/ReportPreviewDO.h"
/*
* 样本条码匹配字段
*/
class SampleBarcodesViewMapper :public Mapper<ReportPreviewDO>
{
public:
	ReportPreviewDO mapper(ResultSet* resultSet) const override
	{
		ReportPreviewDO data;
		data.setPerson_name(resultSet->getString(1));
		data.setSex(resultSet->getString(2));
		data.setId_card(resultSet->getString(3));
		data.setBirth(resultSet->getString(4));
		data.setAge(resultSet->getUInt64(5));
		data.setHome_address(resultSet->getString(6));
		data.setMobile(resultSet->getString(7));
		data.setTest_num(resultSet->getString(8));
		data.setDepartment(resultSet->getString(9));
		data.setDept(resultSet->getString(10));
		data.setCheck_date(resultSet->getString(11));
		data.setOther_hazard_factors(resultSet->getString(12));
		data.setWork_type_text(resultSet->getString(13));
		data.setWork_year(resultSet->getUInt64(14));
		data.setExposure_work_year(resultSet->getUInt64(15));
		data.setEducation(resultSet->getString(16));
		data.setMarriage_date(resultSet->getString(17));
		data.setPeriod(resultSet->getUInt64(18));
		data.setCycle(resultSet->getUInt64(19));
		data.setMenarche(resultSet->getUInt64(20));
		data.setLast_menstruation(resultSet->getString(21));
		data.setExisting_children(resultSet->getString(22));
		data.setAbortion(resultSet->getString(23));
		data.setPremature(resultSet->getString(24));
		data.setDeath(resultSet->getString(25));
		data.setAbnormal_fetus(resultSet->getString(26));
		data.setAllergies(resultSet->getString(27));
		data.setPackage_every_day(resultSet->getUInt64(28));
		data.setSmoke_year(resultSet->getUInt64(29));
		data.setMl_every_day(resultSet->getUInt64(30));
		data.setDrink_year(resultSet->getUInt64(31));
		data.setBirthplace_name(resultSet->getString(32));
		data.setFamily_history(resultSet->getString(33));
		data.setPast_medical_history(resultSet->getString(34));
		data.setDisease_name(resultSet->getString(35));
		return data;
	}
};
/*
* 个人症状匹配字段
*/
class T_symptomMapper :public Mapper<T_symptomDO>
{
public:
	T_symptomDO mapper(ResultSet* resultSet) const override {
		T_symptomDO data;
		data.setProject_name(resultSet->getString(1));
		data.setDegree(resultSet->getString(2));
		data.setCourse_time(resultSet->getString(3));
		return data;
	}
};
#endif // !_SAMPLEBARCODESVIEW_MAPPER_

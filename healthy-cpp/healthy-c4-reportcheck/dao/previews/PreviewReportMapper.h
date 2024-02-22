#pragma once
#ifndef _PREVIEWREPORT_MAPPER_
#define _PREVIEWREPORT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/previews/PreviewReportDO.h"

/**
 * 查询列表表字段匹配映射
 * 负责人Z
 */
class PreviewReportMapper : public Mapper<PreviewReportDO>
{
public:
	PreviewReportDO mapper(ResultSet* resultSet) const override
	{
		PreviewReportDO data;
		data.setId(resultSet->getString(1));
		data.setPerson_name(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setAge(resultSet->getInt(4));
		data.setId_card(resultSet->getString(5));
		data.setMobile(resultSet->getString(6));
		data.setPhysical_type(resultSet->getString(7));
		data.setDept(resultSet->getString(8));
		data.setInspection_date(resultSet->getString(9));
		data.setConclusion(resultSet->getString(10));
		data.setHandle_opinion(resultSet->getString(11));
		data.setInspection_doctor(resultSet->getString(12));
		data.setDiagnostic_unit(resultSet->getString(13));
		return data;
	}
};

#endif // !_PREVIEWREPORT_MAPPER_
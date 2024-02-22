#pragma once
#ifndef _PREVIEWREPORT_MAPPER_
#define _PREVIEWREPORT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/previewreport/PreviewReportDO.h"
/**
 * 字段匹配映射
 * 负责人：小智
 */
class PreviewReportMapper : public Mapper<PreviewReportDO>
{
public:
	PreviewReportDO mapper(ResultSet* resultSet) const override
	{
		PreviewReportDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setAge(resultSet->getUInt(4));
		data.setIdCard(resultSet->getString(5));
		data.setMobile(resultSet->getString(6));
		data.setPhysicalType(resultSet->getString(7));
		data.setDept(resultSet->getString(8));
		data.setConclusion(resultSet->getString(9));
		data.setHandleOpinion(resultSet->getString(10));
		data.setInspectionDoctor(resultSet->getString(11));
		data.setInspectionDate(resultSet->getString(12));
		data.setDiagnosticUnit(resultSet->getString(13));
		return data;
	}
};

#endif // !_PREVIEWREPORT_MAPPER_
#pragma once
#ifndef _MEDEXAMPRINTREPORT_MAPPER_
#define _MEDEXAMPRINTREPORT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/medexamprintreport/MedExamPrintReportDO.h"
/**
 * 字段匹配映射
 * 负责人：小智
 */
class MedExamPrintReportMapper : public Mapper<MedExamPrintReportDO>
{
public:
	MedExamPrintReportDO mapper(ResultSet* resultSet) const override
	{
		MedExamPrintReportDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setAge(resultSet->getUInt(4));
		data.setStatu(resultSet->getBoolean(5));
		data.setPrintState(resultSet->getBoolean(6));
		data.setSporadicPhysical(resultSet->getBoolean(7));
		return data;
	}
};

#endif // !_MEDEXAMPRINTREPORT_MAPPER_
#ifndef _REPORTMAPPER_H_
#define _REPORTMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/report/ReportDO.h"

/*
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ReportMapper : public Mapper<ReportDO>
{
public:
	ReportDO mapper(ResultSet* resultSet) const override
	{
		ReportDO data;
		data.setCode(resultSet->getString(1));
		data.setPhyType(resultSet->getString(2));
		data.setPhyUnit(resultSet->getString(3));
		data.setEnUnit(resultSet->getString(4));
		data.setPhyDate(resultSet->getString(5));
		data.setPhyNum(resultSet->getInt(6));
		data.setHazFactor(resultSet->getString(7));
		data.setPhyProj(resultSet->getString(8));
		data.setEvalBasis(resultSet->getString(9));
		data.setPhyConclusion(resultSet->getString(10));
		return data;
	}
};

#endif 


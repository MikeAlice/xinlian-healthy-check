#pragma once
#ifndef _HEALTH_CERTIFICATE_LIST_MAPPER_
#define _HEALTH_CERTIFICATE_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/healthcertificatelist/HealthCertificateListDO.h"

class HealthCertificateListMapper : public Mapper<HealthCertificateListDO>
{
public:
	HealthCertificateListDO mapper(ResultSet* resultSet) const override
	{
		HealthCertificateListDO data;
		data.setHealth_ccertificate(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setAge(resultSet->getInt(4));
		data.setTerm_of_validity(resultSet->getString(5));
		data.setUnit_of_issue(resultSet->getString(6));
		data.setIs_upload(resultSet->getInt(7));
		return data;
	}
};

#endif // !_HEALTH_CERTIFICATE_LIST_MAPPER_
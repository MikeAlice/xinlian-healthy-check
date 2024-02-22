#pragma once
#ifndef _PRINTMORE_MAPPER_
#define _PRINTMORE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/printmore/PrintMoreDO.h"

/**
 * t_certificate_manage
 */
class CertificateManageMapper : public Mapper<CertificateManageDO>
{
public:
	CertificateManageDO mapper(ResultSet* resultSet) const override
	{
		CertificateManageDO data;
		data.setId(resultSet->getUInt64(1));
		data.setIs_upload(resultSet->getString(2));
		data.setMedical_certificate_id(resultSet->getString(3));
		return data;
	}
};

class DocumentFileMapper : public Mapper<DocumentFileDO>
{
public:
	DocumentFileDO mapper(ResultSet* resultSet) const override
	{
		DocumentFileDO data;
		data.setUrl(resultSet->getString(1));
		return data;
	}
};

#endif // !_PRINTMORE_MAPPER_
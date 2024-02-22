#ifndef _REPORTREVIEW_MAPPER_
#define _REPORTREVIEW_MAPPER_

#include "Mapper.h"
#include "../../domain/do/reportreview/ReportReviewDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ReportReviewMapper : public Mapper<ReportReviewDO>
{
public:
	ReportReviewDO mapper(ResultSet* resultSet) const override
	{
		ReportReviewDO data;
		data.setTestNum(resultSet->getString(1));
		return data;
	}
};

#endif
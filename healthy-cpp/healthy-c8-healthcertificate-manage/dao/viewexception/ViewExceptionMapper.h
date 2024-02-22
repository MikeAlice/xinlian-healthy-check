#pragma once
#ifndef _VIEW_EXCEPTION_MAPPER_
#define _VIEW_EXCEPTION_MAPPER_

#include "Mapper.h"
#include "../../domain/do/viewexception/ViewExceptionDO.h"

class ViewExceptionMapper : public Mapper<ViewExceptionDO>
{
public:
	ViewExceptionDO mapper(ResultSet* resultSet) const override
	{
		ViewExceptionDO data;
		data.setException_message(resultSet->getString(1));
		return data;
	}
};

#endif // !_VIEW_EXCEPTION_MAPPER_
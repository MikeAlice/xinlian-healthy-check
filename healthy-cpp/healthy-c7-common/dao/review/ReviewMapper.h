#pragma once
#ifndef _REVIEW_MAPPER_
#define _REVIEW_MAPPER_

#include "Mapper.h"
#include "../../domain/do/review/ReviewDO.h"

/**
 * �����¼���ֶ�ƥ��ӳ��
 */
class ReviewMapper : public Mapper<ReviewDO>
{
public:
	ReviewDO mapper(ResultSet* resultSet) const override
	{
		ReviewDO data;
		data.setPersonName(resultSet->getString(1)); // 1ָ��ѯ����ĵ�һ��
		data.setCheckProjectName(resultSet->getString(2));
		data.setReviewExplain(resultSet->getString(3));
		data.setReviewTime(resultSet->getString(4));
		data.setCreateTime(resultSet->getString(5));
		data.setState(resultSet->getUInt64(6));
		data.setHazardFactorCode(resultSet->getString(7));
		return data;
	}
};

#endif // !_REVIEW_MAPPER_
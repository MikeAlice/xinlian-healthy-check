#ifndef _UPLOADMORE_MAPPER_
#define _UPLOADMORE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/uploadmore/UploadMoreDO.h"

/**
 * 健康证信息匹配映射
 */
class UploadMoreMapper : public Mapper<UploadMoreDO>
{
public:
	UploadMoreDO mapper(ResultSet* resultSet) const override
	{
		UploadMoreDO data;
		data.setName(resultSet->getString(1));
		data.setSex(resultSet->getString(2));
		data.setAge(resultSet->getInt(3));
		data.setCode(resultSet->getString(4));
		data.setUnitOfIssue(resultSet->getString(5));
		data.setDateOfIssue(resultSet->getString(6));
		data.setTermOfValidity(resultSet->getString(7));
		data.setIsUpload(resultSet->getInt(8));
		return data;
	}
};

//文件地址映射
class UpLoadUrlMapper : public Mapper<UploadMoreDO>
{
public:
	UploadMoreDO mapper(ResultSet* resultSet) const override
	{
		UploadMoreDO data;
		data.setUrl(resultSet->getString(1));
		return data;
	}
};

#endif 
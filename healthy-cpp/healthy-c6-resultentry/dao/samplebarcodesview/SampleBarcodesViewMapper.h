#ifndef _REPORTPREVIEW_MAPPER_
#define _REPORTPREVIEW_MAPPER_
#include "Mapper.h"
#include"domain/do/samplebarcodesview/SampleBarcodesViewDO.h"
/*
* Ñù±¾ÌõÂëÆ¥Åä×Ö¶Î
*/
class SampleBarcodesViewMapper :public Mapper<SampleBarcodesViewDO>
{
public:
	SampleBarcodesViewDO mapper(ResultSet* resultSet) const override
	{
		SampleBarcodesViewDO data;
		data.setAge(resultSet->getUInt64(1));
		data.setBarcode(resultSet->getString(2));
		data.setGroup_item_name(resultSet->getString(3));
		data.setPerson_name(resultSet->getString(4));
		data.setSex(resultSet->getString(5));
		data.setTest_num(resultSet->getString(6));
		return data;
	}
};

#endif // !_SAMPLEBARCODESVIEW_MAPPER_

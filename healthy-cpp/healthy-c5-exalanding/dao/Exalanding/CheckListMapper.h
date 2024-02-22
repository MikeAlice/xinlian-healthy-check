#pragma once
#ifndef _CHECKLIST_MAPPER_
#define _CHECKLIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Exalanding/CheckListDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class CheckListMapper : public Mapper<CheckListDO>
{
public:
	CheckListDO mapper(ResultSet* resultSet) const override
	{
		CheckListDO data;
		data.setItem(resultSet->getString(1));
		data.setId_card(resultSet->getString(2));
		data.setDiscount(resultSet->getUInt(3));
		data.setDiscount_price(resultSet->getDouble(4));
		data.setPhysical_type(resultSet->getString(5));
		return data;
	}
};

#endif // !_CHECK_MAPPER_
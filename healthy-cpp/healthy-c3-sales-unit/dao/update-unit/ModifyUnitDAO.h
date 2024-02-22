#pragma once

#ifndef _MODIFYUNITDAO_H_
#define _MODIFYUNITDAO_H_

#include "BaseDAO.h"
#include "../../domain/do/update-unit/UnitDetailDO.h"
#include "../../domain/do/update-unit/TestDetailDO.h"
#include <list>

class ModifyUnitDAO : public BaseDAO
{
public:
	int updateUnit(const UnitDetailDO& unitDO);
	int deleteTest(const std::string delTestId, const std::string unitId,const std::string deleteId, const std::string deleteTime);
	int updateTest(std::list<TestDetailDO>& testListDO);
};

#endif // !_MODIFYUNITDAO_H_

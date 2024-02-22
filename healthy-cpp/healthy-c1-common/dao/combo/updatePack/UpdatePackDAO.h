#pragma once

#ifndef _DELPACKDAO_H_
#define _DELPACKDAO_H_
#include "BaseDAO.h"
#include "domain/do/combo/UpdatePackDO.h"

class UpdatePackDAO : public BaseDAO
{
public:
	// ÐÞ¸ÄÊý¾Ý
	int update(const UpdatePackDO& iObj);
};
#endif // _ADDPACKDAO_H_
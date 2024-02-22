#pragma once

#ifndef _ADDPACKDAO_H_
#define _ADDPACKDAO_H_
#include "BaseDAO.h"
#include "domain/do/combo/AddPackDO.h"

class AddPackDAO : public BaseDAO
{
public:
	// 插入数据	负责人：熊猫
	uint64_t insert(const AddPackDO& iObj);
};
#endif // _ADDPACKDAO_H_
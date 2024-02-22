#pragma once

#ifndef _DELPACKDAO_H_
#define _DELPACKDAO_H_
#include "BaseDAO.h"
#include "domain/do/combo/DelPackDO.h"

class DelPackDAO : public BaseDAO
{
public:
	// 删除数据	负责人：熊猫
	// 通过ID删除数据
	int deleteById(string id);
};
#endif // _ADDPACKDAO_H_
#pragma once

#ifndef _ADDPACKDAO_H_
#define _ADDPACKDAO_H_
#include "BaseDAO.h"
#include "domain/do/combo/AddPackDO.h"

class AddPackDAO : public BaseDAO
{
public:
	// ��������	�����ˣ���è
	uint64_t insert(const AddPackDO& iObj);
};
#endif // _ADDPACKDAO_H_
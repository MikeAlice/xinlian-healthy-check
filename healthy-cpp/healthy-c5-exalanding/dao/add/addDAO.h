#pragma once
#ifndef _ADD_DAO_
#define _ADD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/add/addDO.h"
#include "../../domain/query/add/AddUnit.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class addDAO : public BaseDAO
{
public:
	// ��������
	uint64_t insert(const addDO& iObj);

};
#endif // !_SAMPLE_DAO_
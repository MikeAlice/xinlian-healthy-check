#pragma once
#ifndef _ADDNEWITEMS_DAO_
#define _ADDNEWITEMS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/addNewItems/AddNewItemsDO.h"
#include "../../domain/query/addNewItems/AddNewItemsQuery.h"

/**
 * ���������¼�����ݿ����ʵ��
 */
class AddNewItemsDAO : public BaseDAO
{
public:
	// ��������
	uint64_t insert(const AddNewItemsDO& iObj);
};
#endif // !_ADDNEWITEMS_DAO_
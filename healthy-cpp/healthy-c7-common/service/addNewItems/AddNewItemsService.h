#pragma once
#ifndef _ADDNEWITEMS_SERVICE_
#define _ADDNEWITEMS_SERVICE_
#include <list>
#include "domain/vo/addNewItems/AddNewItemsVO.h"
#include "domain/query/addNewItems/AddNewItemsQuery.h"
#include "domain/dto/addNewItems/AddNewItemsDTO.h"

/**
 * ���������������¼����ʵ��
 */
class AddNewItemsService
{
public:
	// ��������  ����
	uint64_t saveData(const AddNewItemsDTO::Wrapper& dto);
};

#endif // !_ADDNEWITEMS_SERVICE_
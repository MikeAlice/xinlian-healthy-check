#pragma once
#ifndef _PRINT_CONFIRM_DAO_
#define _PRINT_CONFIRM_DAO_
#include "BaseDAO.h"
#include "../../domain/do/printconfirm/PrintConfirmDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class PrintConfirmDAO : public BaseDAO
{
public:
	int update(string uObj);
};
#endif // !_PRINT_CONFIRM_DAO_
#pragma once
#ifndef _PRINT_CONFIRM_DAO_
#define _PRINT_CONFIRM_DAO_
#include "BaseDAO.h"
#include "../../domain/do/printconfirm/PrintConfirmDO.h"

/**
 * 示例表数据库操作实现
 */
class PrintConfirmDAO : public BaseDAO
{
public:
	int update(string uObj);
};
#endif // !_PRINT_CONFIRM_DAO_
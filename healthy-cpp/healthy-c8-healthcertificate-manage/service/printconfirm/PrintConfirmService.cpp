#include"stdafx.h"
#include "PrintConfirmService.h"
#include "../../dao/printconfirm/PrintConfirmDAO.h"


uint64_t PrintConfirmService::saveData(const PrintConfirmDTO::Wrapper& dto)
{
	return uint64_t();
}

bool PrintConfirmService::updateData(string order_id)
{
	PrintConfirmDAO dao;
	return dao.update(order_id) == 1;
}

bool PrintConfirmService::removeData(uint64_t id)
{
	return false;
}

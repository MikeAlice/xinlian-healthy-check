#include "stdafx.h"
#include "perdelService.h"
#include "../../dao/questatistics/perdelDAO.h"

// 通过id删除体检人员
bool perdelService::removeData(const std::string& id)
{
	perdelDAO dao;
	return dao.deleteByPersonId(id) > 0;
}

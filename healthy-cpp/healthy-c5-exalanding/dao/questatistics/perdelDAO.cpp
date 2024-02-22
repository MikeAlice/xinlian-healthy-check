#include "stdafx.h"
#include "perdelDAO.h"
#include <sstream>

// 通过id删除体检人员
int perdelDAO::deleteByPersonId(const string& id)
{
	string sql;
	sql = "DELETE FROM `t_group_person` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}
#include "stdafx.h"
#include "perdelDAO.h"
#include <sstream>

// ͨ��idɾ�������Ա
int perdelDAO::deleteByPersonId(const string& id)
{
	string sql;
	sql = "DELETE FROM `t_group_person` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}
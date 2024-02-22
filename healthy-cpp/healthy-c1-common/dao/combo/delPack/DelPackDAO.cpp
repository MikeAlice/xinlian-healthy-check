#include "DelPackDAO.h"

int DelPackDAO::deleteById(string id)
{
	string sql = "DELETE FROM `t_combo` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);

}
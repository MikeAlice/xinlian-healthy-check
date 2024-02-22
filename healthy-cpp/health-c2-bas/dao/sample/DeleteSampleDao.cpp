#include "stdafx.h"
#include "DeleteSampleDao.h"
#include "DeleteSampleMapper.h"
#include <sstream>



int DeleteSampleDAO::deleteById(const string& id)
{
	string sql = "DELETE FROM `t_sample` WHERE `id`=?";

	return sqlSession->executeUpdate(sql, "%s", id);
}
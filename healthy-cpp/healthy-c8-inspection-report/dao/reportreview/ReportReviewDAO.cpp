#include "stdafx.h"
#include "ReportReviewDAO.h"
#include "ReportReviewMapper.h"
#include <sstream>

int ReportReviewDAO::update(const ReportReviewDO& uObj)
{
	string sql = "UPDATE `t_group_person` SET `statu`=1 WHERE `test_num`=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getTestNum());
}

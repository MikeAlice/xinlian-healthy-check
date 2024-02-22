#include "stdafx.h"
#include "PrintReportDAO.h"
#include <sstream>

int PrintReportDAO::update(const PrintReportDO & uObj)
{
	string sql = "UPDATE `t_group_person` SET `report_printing_num`=?, `print_state`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%d%d%s", uObj.getReportPrintingNum(), uObj.getPrintState(), uObj.getId());
}
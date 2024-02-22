#include "stdafx.h"
#include "ReportDAO.h"
#include "ReportMapper.h"
#include <sstream>

list<ReportDO> ReportDAO::selectById(const string& id)
{
	string sql = "SELECT `code`,`physical_type`, `physical_unit`,`entrust_unit`, `physical_date`,`physical_number`,`hazard_factors`,`physical_project`, `evaluation_basis`, `concluding_observations` FROM t_unit_report WHERE `id` = ?";
	ReportMapper mapper;
	return sqlSession->executeQuery<ReportDO, ReportMapper>(sql, mapper, "%s", id);
}

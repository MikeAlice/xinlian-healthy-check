#include "stdafx.h"
#include <sstream>
#include "ReportDAO.h"
#include "ReportMapper.h"
#include "domain/do/ReportView/ReportDO.h"



list<ReportDO> ReportDAO::selectByName(const string& nameID)
{
	std::string sql = "SELECT "
		"t_inspection_record.person_id AS id, "
		"t_group_person.person_name, "
		"t_group_person.sex, "
		"t_group_person.age, "
		"t_group_person.id_card, "
		"t_group_person.mobile, "
		"t_group_person.physical_type, "
		"t_group_person.dept, "
		"t_inspection_record.conclusion, "
		"t_inspection_record.handle_opinion, "
		"t_inspection_record.inspection_doctor, "
		"t_inspection_record.inspection_date, "
		"t_group_person.diagnostic_unit "
		"FROM "
		"t_inspection_record "
		"INNER JOIN "
		"t_group_person ON t_inspection_record.person_id = t_group_person.id "
		"WHERE "
		"t_inspection_record.id = ? ;";
	ReportMapper mapper;
	return sqlSession->executeQuery<ReportDO, ReportMapper>(sql, mapper, "%s", nameID);
}

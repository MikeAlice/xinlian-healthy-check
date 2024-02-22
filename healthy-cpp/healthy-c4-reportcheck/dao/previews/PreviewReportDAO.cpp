#include "stdafx.h"
#include "PreviewReportDAO.h"
#include "PreviewReportMapper.h"
#include <sstream>

list<PreviewReportDO> PreviewReportDAO::selectByName(const string & name)
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
        "t_inspection_record.inspection_date, "
        "t_inspection_record.conclusion, "
        "t_inspection_record.handle_opinion, "
        "t_inspection_record.inspection_doctor, "
        "t_group_person.diagnostic_unit "
        "FROM "
        "t_inspection_record "
        "INNER JOIN "
        "t_group_person ON t_inspection_record.person_id = t_group_person.id "
        "WHERE "
        "t_inspection_record.id =? ;";
	PreviewReportMapper mapper;
	return sqlSession->executeQuery<PreviewReportDO, PreviewReportMapper>(sql, mapper, "%s", name);
}
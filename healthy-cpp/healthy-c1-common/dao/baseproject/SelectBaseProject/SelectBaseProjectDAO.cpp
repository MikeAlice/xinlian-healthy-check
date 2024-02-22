#include "stdafx.h"
#include "SelectBaseProjectDAO.h"
#include "SelectBaseProjectMapper.h"
#include <sstream>

#define SELECTBASEPROJECT_TERAM_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->id) { \
    sql << " AND `id`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
}

uint64_t SelectBaseProjectDAO::count(const SelectBaseProjectQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_base_project";
    SELECTBASEPROJECT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<SelectBaseProjectDO> SelectBaseProjectDAO::selectWithPage(const SelectBaseProjectQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT id, code, name, short_name, order_num, office_id, office_name, unit_code, unit_name, default_value, result_type, in_conclusion, in_report, relation_code, del_flag, create_id, create_time, update_id, update_time, delete_id, delete_time, department_id FROM t_base_project";

    SELECTBASEPROJECT_TERAM_PARSE(query, sql);
    sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
    SelectBaseProjectMapper mapper;
    string sqlStr = sql.str();
    return sqlSession->executeQuery<SelectBaseProjectDO, SelectBaseProjectMapper>(sqlStr, mapper, params);
}

std::list<SelectBaseProjectDO> SelectBaseProjectDAO::selectById(const string& id)
{
    string sql = "SELECT id, code, name, short_name, order_num, office_id, office_name, unit_code, unit_name, default_value, result_type, in_conclusion, in_report, relation_code, del_flag, create_id, create_time, update_id, update_time, delete_id, delete_time, department_id FROM t_base_project WHERE id=?";
    SelectBaseProjectMapper mapper;
    return sqlSession->executeQuery<SelectBaseProjectDO, SelectBaseProjectMapper>(sql, mapper, "%s", id);
}

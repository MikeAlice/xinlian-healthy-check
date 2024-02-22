#include "stdafx.h"
#include "TicketGroupNameListDAO.h"
#include "TicketGroupNameListMapper.h"
#include <sstream>
//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->Unit_name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
} \


std::list<TicketGroupNameListDO> TicketGroupNameListDAO::selectByName(const string& Unit_name)
{
	string sql = "SELECT t_order_group.name FROM t_test_record INNER JOIN t_order_group ON t_test_record.id = t_order_group.group_order_id WHERE t_test_record.unit_id IN(SELECT id FROM t_group_unit WHERE name LIKE CONCAT('%', ? , '%'))";
	TicketGroupNameListMapper mapper;
	return sqlSession->executeQuery<TicketGroupNameListDO, TicketGroupNameListMapper>(sql, mapper, "%s", Unit_name);
}
//SELECT t_order_group.name
//FROM t_test_record
//INNER JOIN t_order_group ON t_test_record.id = t_order_group.group_order_id
//WHERE t_test_record.unit_id IN(
//	SELECT id FROM t_group_unit WHERE name LIKE CONCAT('%', ? , '%')
//)
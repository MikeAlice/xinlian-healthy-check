#include "stdafx.h"
#include "PrintConfirmDAO.h"
#include "PrintConfirmMapper.h"

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}

int PrintConfirmDAO::update(string uObj)
{
	//string sql = "UPDATE `t_group_person` SET `health_ccertificate`=?  WHERE `health_ccertificate`=?";
	string sql = "UPDATE `t_review_person` SET `print_state` = 1 WHERE `order_id` = ?";
	/*
	string sql =
		" BEGIN; \
	UPDATE `t_group_person` \
		SET `print_state` = -1 \
		WHERE  `order_id` = ?; \
 \
	UPDATE `t_review_person` \
		SET `print_state` = -1 \
		WHERE `order_id` = ?; \
		 COMMIT; ";
		 */

	return sqlSession->executeUpdate(sql, "%s", uObj);
}

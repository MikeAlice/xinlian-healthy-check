#include "stdafx.h"
#include "AddNewItemsDAO.h"
#include "AddNewItemsMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define ADDNEWITEMS_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->checkProjectId) { \
	sql << " AND check_project_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->checkProjectId.getValue("")); \
} \
if (query->checkProjectName) { \
	sql << " AND check_project_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->checkProjectName.getValue("")); \
} \
if (query->portfolioProjectId) { \
	sql << " AND portfolio_project_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->portfolioProjectId.getValue("")); \
} \
if (query->portfolioProjectName) { \
	sql << " AND portfolio_project_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->portfolioProjectName.getValue("")); \
} \
if (query->reason) { \
	sql << " AND reason=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->reason.getValue("")); \
}

// 插入数据
uint64_t AddNewItemsDAO::insert(const AddNewItemsDO& iObj)
{
	string sql = "INSERT INTO `t_review_record` (`id`, `check_project_id`, `check_project_name`) VALUES (?, ?, ?)";
	sqlSession->executeInsert(sql, "%s%s%s", iObj.getId(), iObj.getCheckProjectId(), iObj.getCheckProjectName());
	const string sql1 = "SELECT COUNT(*) FROM t_review_record WHERE id="+iObj.getId();
	return sqlSession->executeQueryNumerical(sql1);
}
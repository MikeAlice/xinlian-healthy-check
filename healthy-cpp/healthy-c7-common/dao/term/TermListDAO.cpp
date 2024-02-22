#include "stdafx.h"
#include "TermListDAO.h"
#include "TermListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->officeId) { \
	sql << " AND `office_id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->officeId.getValue("")); \
} \
if (query->hazardFactorsText) { \
	sql << " AND hazard_factors_text=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->hazardFactorsText.getValue("")); \
} \
if (query->inspectType) { \
	sql << " AND `inspect_type`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->inspectType.getValue("")); \
} \
if (query->content) { \
	sql << " AND `content`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->content.getValue("")); \
} \
if (query->workStateText) { \
	sql << " AND work_state_text=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workStateText.getValue("")); \
}

uint64_t TermListDAO::count(const TermQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_office_term";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<TermListDO> TermListDAO::selectWithPage(const TermQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT id,office_id,hazard_factors_text,inspect_type,content,work_state_text FROM t_office_term";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	TermMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<TermListDO, TermMapper>(sqlStr, mapper, params);

}


std::list<TermListDO> TermListDAO::selectByOfficeId(const string& officeId)
{
	string sql = "SELECT id,office_id,hazard_factors_text,inspect_type,content,work_state_text FROM t_office_term WHERE `office_id` LIKE CONCAT('?',?,'?','?',?,'?')";
	TermMapper mapper;
	return sqlSession->executeQuery<TermListDO, TermMapper>(sql, mapper, "%s", officeId);

}

uint64_t TermListDAO::insert(const TermListDO& iObj)
{
	string sql = "INSERT INTO `t_office_term` (`office_id`, `hazard_factors_text`, `inspect_type`, `content`, `work_state_text`) VALUES (?, ?, ?,?,?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s", iObj.getOfficeId(), iObj.getHazardFactorsText(), iObj.getInspectType(),iObj.getContent(),iObj.getWorkStateText());
}

int TermListDAO::update(const TermListDO& uObj)
{
	string sql = "UPDATE `t_office_term` SET `office_id`=?, `hazard_factors_text`=?, `inspect_type`=?, `content`=?, `work_state_text`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%ull", uObj.getOfficeId(), uObj.getHazardFactorsText(), uObj.getInspectType(), uObj.getContent(), uObj.getWorkStateText(), uObj.getId());
}

int TermListDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `t_office_term` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);

}



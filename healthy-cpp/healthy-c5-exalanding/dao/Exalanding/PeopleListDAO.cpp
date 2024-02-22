#include "stdafx.h"
#include "PeopleListDAO.h"
#include "PeopleListMapper.h"
#include <sstream>
//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->personName) { \
	sql << " AND `person_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->personName.getValue("")); \
} \
if (query->physical) { \
	sql << " AND physical_type=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->physical.getValue("")); \
} \

uint64_t PeopleListDAO::count(const PeopleListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<PeopleListDO> PeopleListDAO::selectWithPage(const PeopleListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT id,person_name,sex,age,jc_type,sporadic_physical FROM t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	PeopleListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PeopleListDO, PeopleListMapper>(sqlStr, mapper, params);
}

std::list<PeopleListDO> PeopleListDAO::selectByName(const string& name)
{
	string sql = "SELECT id,person_name,sex,age,jc_type,sporadic_physical FROM t_group_person WHERE `person_name` LIKE CONCAT('%',?,'%')";
	PeopleListMapper mapper;
	return sqlSession->executeQuery<PeopleListDO, PeopleListMapper>(sql, mapper, "%s", name);
}

uint64_t PeopleListDAO::insert(const PeopleListDO& iObj)
{
	string sql = "INSERT INTO `t_group_person` (`person_name`, `sex`, `age`, `jc_type`, `sporadic_physical`) VALUES (?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getPerson_name(), iObj.getSex(), iObj.getAge(), iObj.getJc_type(), iObj.getSporadic_physical());
}

int PeopleListDAO::update(const PeopleListDO& uObj)
{
	string sql = "UPDATE `t_group_person` SET `person_name`=?, `sex`=?, `age`=?, `jc_type`=?, `sporadic_physical`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getPerson_name(), uObj.getSex(), uObj.getAge(), uObj.getId(), uObj.getJc_type(), uObj.getSporadic_physical());
}

int PeopleListDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `t_group_person` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

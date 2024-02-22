#include "stdafx.h"
#include "ObtainSampleListDAO.h"
#include "ObtainSampleListMapper.h"
#include <sstream>
//ObtainSampleList
//定义条件解析宏，减少重复代码
#define INSERT_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->code) { \
	sql << " AND code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue("")); \
}\
if (query->liscode) {\
	\
		sql << " AND liscode=?"; \
		SQLPARAMS_PUSH(params, "s",std::string, query->liscode.getValue("")); \
}



uint64_t ObtainSampleListDAO::count(const ObtainSampleListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_sample";
	INSERT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ObtainSampleListDO> ObtainSampleListDAO::selectWithPage(const ObtainSampleListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT name,code,liscode FROM t_sample";
	INSERT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ObtainSampleListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ObtainSampleListDO, ObtainSampleListMapper>(sqlStr, mapper, params);

}


list<ObtainSampleListDO> ObtainSampleListDAO::selectByName(const string& name)
{
	string sql = "SELECT name,code,liscode FROM t_sample WHERE `name` LIKE CONCAT('%',?,'%')";
	ObtainSampleListMapper mapper;
	return sqlSession->executeQuery<ObtainSampleListDO, ObtainSampleListMapper>(sql, mapper, "%s", name);

}

uint64_t ObtainSampleListDAO::insert(const ObtainSampleListDO& iObj)
{
	string sql = "INSERT INTO `t_sample` (`name`, 'code','liscode') VALUES (? , ? , ?)";
	return sqlSession->executeInsert(sql, "%s%s%s", iObj.getName(),  iObj.getCode(),   iObj.getLiscode());

}



int ObtainSampleListDAO::update(const ObtainSampleListDO& uObj)
{
	string sql = "UPDATE `t_sample` SET `name`=?,'code'=?,'liscode'=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%ull", uObj.getName(),uObj.getCode(), uObj.getLiscode());

}

int ObtainSampleListDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `t_sample` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

#include "stdafx.h"
#include "UnitListDAO.h"
#include "UnitListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->personName) { \
	sql << " AND `person_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->personName.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}\
if (query->physicalType) {\
		sql << " AND physical_type=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->physicalType.getValue("")); \
}\
if (query->sporadicPhysical) {\
		sql << " AND sporadic_physical=?"; \
		SQLPARAMS_PUSH(params, "i", int, query->sporadicPhysical.getValue(0)); \
}\

uint64_t UnitListDAO::count(const UnitQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person";
	SqlParams params; sql << " WHERE 1=1"; if (query->personName) {
		sql << " AND `person_name`=?"; params.emplace_back(SqlParam("s", std::make_shared<std::string>(query->personName.getValue(""))));
	} if (query->sex) {
		sql << " AND sex=?"; params.emplace_back(SqlParam("s", std::make_shared<std::string>(query->sex.getValue(""))));
	} if (query->age) {
		sql << " AND age=?"; params.emplace_back(SqlParam("i", std::make_shared<int>(query->age.getValue(0))));
	}if (query->physicalType) {
		sql << " AND physical_type=?"; params.emplace_back(SqlParam("s", std::make_shared<std::string>(query->physicalType.getValue(""))));
	}if (query->sporadicPhysical) {
		sql << " AND sporadic_physical=?"; params.emplace_back(SqlParam("i", std::make_shared<int>(query->sporadicPhysical.getValue(0))));
	};
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<UnitListDO> UnitListDAO::selectWithPage(const UnitQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT person_name,sex,age,physical_type,sporadic_physical FROM t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	UnitListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<UnitListDO, UnitListMapper>(sqlStr, mapper, params);
}

list<UnitListDO> UnitListDAO::selectByName(const string& person_name)
{
	string sql = "SELECT person_name,sex,age,physical_type,sporadic_physical FROM t_group_person WHERE person_name LIKE CONCAT('%',?,'%')";
	UnitListMapper mapper;
	return sqlSession->executeQuery<UnitListDO, UnitListMapper>(sql, mapper, "%s", person_name);
}

/*
uint64_t UnitListDAO::insert(const UnitListDO& iObj)
{
	string sql = "INSERT INTO `t_group_person` (`person_name`,`sex`,`age`,`physical_type`,`sporadic_physical`) VALUES (?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i%s%i", iObj.getPersonName(), iObj.getSex(), iObj.getAge(), iObj.getPhysicalType(), iObj.getSporadicPhysical());
}*/

/*
int UnitListDAO::update(const UnitListDO& uObj)//有问题
{
	string sql = "UPDATE `t_group_person` SET `person_name`=?, `sex`=?, `age`=?, `physical_type`=?,`sporadic_physical`=?WHERE ";
	return sqlSession->executeInsert(sql, "%s%s%i%s%i", uObj.getPersonName(), uObj.getSex(), uObj.getAge(), uObj.getPhysicalType(), uObj.getSporadicPhysical());
	//return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
}
*/

/*
int UnitListDAO::deleteById(uint64_t id)
{
	return 0;
}
*/

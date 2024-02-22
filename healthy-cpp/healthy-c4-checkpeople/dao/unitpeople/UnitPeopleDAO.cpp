#include "stdafx.h"
#include "UnitPeopleMapper.h"
#include <sstream>
#include "UnitPeopleDAO.h"


//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id_card) { \
	sql << " AND `id_card`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id_card.getValue("")); \
} \
if (query->person_name) { \
	sql << " AND person_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->person_name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
}if (query->birth) { \
	sql << " AND birth=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->birth.getValue("")); \
}if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}if (query->is_marry) { \
	sql << " AND is_marry=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_marry.getValue("")); \
}if (query->mobile) { \
	sql << " AND mobile=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->mobile.getValue("")); \
}



uint64_t UnitPeopleDAO::count(const UnitPeopleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<UnitPeopleDO> UnitPeopleDAO::selectWithPage(const UnitPeopleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT id_card,person_name,sex,birth,age,is_marry,mobile FROM t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	UnitPeopleMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<UnitPeopleDO, UnitPeopleMapper>(sqlStr, mapper, params);
}

list<UnitPeopleDO> UnitPeopleDAO::selectByidCard(const string& id_card)
{
	string sql = "SELECT id_card ,person_name,sex,birth ,age ,is_marry,mobile FROM t_group_person WHERE `id_card` LIKE CONCAT(?,'%','%','%','%','%','%')";
	UnitPeopleMapper mapper;
	return sqlSession->executeQuery<UnitPeopleDO, UnitPeopleMapper>(sql, mapper, "%s", id_card);
}

uint64_t UnitPeopleDAO::insert(const UnitPeopleDO& iObj)
{
	string sql = "INSERT INTO `t_group_person` (`id_card`, `person_name`, `sex`,`birth`, `age`, `is_marry`,`mobile`) VALUES (?, ?, ? ,? ,? ,? ,?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%i%s%s", iObj.getIdCard(), iObj.getPersonName(), iObj.getSex(), iObj.getBirth(), iObj.getAge(), iObj.getIsMarry(), iObj.getMobile());
}

int UnitPeopleDAO::update(const UnitPeopleDO& uObj)
{
	return 0;
}

int UnitPeopleDAO::deleteById(uint64_t id)
{
	return 0;
}

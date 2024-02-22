#include "stdafx.h"
#include "ReferenceModMapper.h"
#include <sstream>

#include "ReferenceModDAO.h"

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



//修改数据
int ReferenceModDAO::update(const ReferenceModDO & uObj)
{
	string sql = "UPDATE `relation_project_reference` SET `allow_sex`=?, `min_age`=?, `max_age`=?, `healthy_value`=?, `occupation_value`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%i%i%s%s%s", uObj.getAllowSex(), uObj.getMinAge(), uObj.getMaxAge(), uObj.getHealthyValue(), uObj.getOccupationValue(), uObj.getId());
}

#include "stdafx.h"
#include "SaveInfoDAO.h"
#include "SaveInfoMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id_card) { \
	sql << " AND `id_card`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id_card.getValue("")); \
} \
if (query->person_name) { \
	sql << " AND `person_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->person_name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND `sex`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND `age`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}\
if (query->mobile) { \
	sql << " AND `mobile`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->mobile.getValue("")); \
} \
if (query->is_marry) { \
	sql << " AND `is_marry`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_marry.getValue("")); \
} \
if (query->id) { \
	sql << " AND `id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->is_pass) { \
	sql << " AND `is_pass`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->is_pass.getValue(0)); \
} \
if (query->physical_type) { \
	sql << " AND `physical_type`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->physical_type.getValue("")); \
}

uint64_t SaveInfoDAO::insert(const SaveInfoDO & iObj)
{
	string sql = "INSERT INTO `t_group_person` (`id`,`id_card`,`person_name`, `sex`, `age`,`mobile`,`is_marry`,`is_pass`,`physical_type`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%i%s%s%i%s", iObj.getId(), iObj.getId_card(), iObj.getPerson_name(), iObj.getSex(), iObj.getAge(), iObj.getMobile(), iObj.getIs_marry(), iObj.getIs_pass(), iObj.getPhysical_type());
}                  
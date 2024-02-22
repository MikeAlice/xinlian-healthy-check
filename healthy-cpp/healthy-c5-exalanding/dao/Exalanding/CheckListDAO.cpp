#include "stdafx.h"
#include "CheckListDAO.h"
#include "CheckListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->item) { \
	sql << " AND `item`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->item.getValue("")); \
} \
if (query->id_card) { \
	sql << " AND id_card=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id_card.getValue("")); \
} \
if (query->discount) { \
	sql << " AND discount=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->discount.getValue(0)); \
} \
if (query->discount_price) { \
	sql << " AND discount_price=?"; \
	SQLPARAMS_PUSH(params, "f", float, query->discount_price.getValue(0)); \
} \
if (query->physical_type) { \
	sql << " AND physical_type=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->physical_type.getValue("")); \
} \

uint64_t CheckListDAO::count(const CheckListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_order_group_item";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<CheckListDO> CheckListDAO::selectWithPage(const CheckListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT item,id_card,discount,discount_price,physical_type FROM t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	CheckListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CheckListDO, CheckListMapper>(sqlStr, mapper, params);
}

uint64_t CheckListDAO::insert(const CheckListDO& iObj)
{
	string sql = "INSERT INTO `t_order_group_item` (`item`, `id_card`, `discount`, `discount_price`, `physical_type`) VALUES (?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i%f%s", iObj.getItem(), iObj.getId_card(), iObj.getDiscount(), iObj.getDiscount_price(), iObj.getPhysical_type());
}

int CheckListDAO::update(const CheckListDO& uObj)
{
	string sql = "UPDATE `t_order_group_item` SET `item`=?, `id_card`=?, `discount`=? WHERE `id`=?, WHERE `discount_price`=?, WHERE `physical_type`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getItem(), uObj.getId_card(), uObj.getDiscount(), uObj.getDiscount_price(), uObj.getPhysical_type());
}

int CheckListDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `t_order_group_item` WHERE `id_card`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

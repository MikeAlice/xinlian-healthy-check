
#include "stdafx.h"
#include "InsertSampleDAO.h"
#include "InsertSampleMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define INSERT_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->spec) { \
	sql << " AND spec=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->spec.getValue("")); \
} \
if (query->code) { \
	sql << " AND code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue("")); \
}\
if (query->is_print) {\
	\
		sql << " AND `is_print`=?"; \
		SQLPARAMS_PUSH(params, "i",  int, query->is_print.getValue(0)); \
} \
if (query->capacity) {\
	\
		sql << " AND capacity=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->capacity.getValue("")); \
} \
if (query->barcode_num) {\
	\
		sql << " AND barcode_num=?"; \
		SQLPARAMS_PUSH(params, "i", int, query->barcode_num.getValue(0)); \
}\
if (query->need_take_blood) {\
	\
		sql << " AND `need_take_blood`=?"; \
		SQLPARAMS_PUSH(params, "i", int, query->need_take_blood.getValue(0)); \
} \
if (query->order_num) {\
	\
		sql << " AND order_num=?"; \
		SQLPARAMS_PUSH(params, "f",float, query->order_num.getValue(0)); \
} \
if (query->liscode) {\
	\
		sql << " AND liscode=?"; \
		SQLPARAMS_PUSH(params, "s",std::string, query->liscode.getValue("")); \
}\

uint64_t InsertSampleDAO::count(const InsertSampleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_sample";
	INSERT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<InsertSampleDO> InsertSampleDAO::selectWithPage(const InsertSampleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT name,spec,code,is_print,capacity,barcode_num,need_take_blood,order_num,liscode FROM t_sample";
	INSERT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	InsertSampleMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<InsertSampleDO, InsertSampleMapper>(sqlStr, mapper, params);

}

//
//list<InsertSampleDO> InsertSampleDAO::selectByName(const string& name)
//{
//	string sql = "SELECT name,spec,code,is_print,capacity,barcode_num,need_take_blood,order_num,liscode FROM t_sample WHERE `name` LIKE CONCAT('%',?,'%')";
//	InsertSampleMapper mapper;
//	return sqlSession->executeQuery<InsertSampleDO, InsertSampleMapper>(sql, mapper, "%s", name);
//
//}


uint64_t InsertSampleDAO::insert(const InsertSampleDO& iObj)
{
	string sql = "INSERT INTO `t_sample` (`id`,`name`, `spec`,`code`,`is_print`,`capacity`,`barcode_num`,`need_take_blood`,`order_num`,`liscode`,`del_flag`) VALUES (?,?,?,?,?,?,?,?,?,?,0)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%ui%s%ui%ui%d%s",iObj.getId(), iObj.getName(), iObj.getSpec(),
		iObj.getCode(), iObj.getIs_print(), iObj.getCapacity(), iObj.getBarcode_num(), iObj.getNeed_take_blood(),
		iObj.getOrder_num(), iObj.getLiscode());
	

		/*string sql = "INSERT INTO `t_sample` (`id`,`name`, `spec`,`code`,`is_print`,`capacity`,`liscode`,`barcode_num`,`need_take_blood`,`order_num`,`del_flag`) VALUES (?,?,?,?,?,?,?,?,?,?,0)";
		return sqlSession->executeUpdate(sql, "%s%s%s%s%ui%s%s%ui%ui%ui",iObj.getId(), iObj.getName(), iObj.getSpec(),
			iObj.getCode(), iObj.getIs_print(), iObj.getCapacity(), iObj.getLiscode(), iObj.getBarcode_num(), iObj.getNeed_take_blood()
			, iObj.getOrder_num());*/
}




//
//
//int InsertSampleDAO::update(const InsertSampleDO& uObj)
//{
//	string sql = "UPDATE `t_sample` SET `name`=?, 'spec'=?,'code'=?,'is_print'=?,'capacity'=?,'barcode_num'=?,'need_take_blood'=?,'order_num'=?,'liscode'=? WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%s%s%s%i%s%i%i%lf%s%ull", uObj.getName(), uObj.getSpec(), uObj.getCode(), uObj.getIs_print(), uObj.getCapacity(), uObj.getBarcode_num(), uObj.getNeed_take_blood(), uObj.getOrder_num(), uObj.getLiscode());
//
//}
//
//int InsertSampleDAO::deleteById(uint64_t id)
//{
//	string sql = "DELETE FROM `t_sample` WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%ull", id);
//}


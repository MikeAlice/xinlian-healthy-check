#include "stdafx.h"
#include "ReviewDAO.h"
#include "ReviewMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define REVIEW_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id) { \
	sql << " AND `id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->personId) { \
	sql << " AND person_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->personId.getValue("")); \
} \
if (query->checkProjectId) { \
	sql << " AND check_project_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->checkProjectId.getValue("")); \
} \
if (query->checkProjectName) { \
	sql << " AND check_project_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->checkProjectName.getValue("")); \
} \
if (query->reviewExplain) { \
	sql << " AND review_explain=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->reviewExplain.getValue("")); \
} \
if (query->reviewTime) { \
	sql << " AND review_time=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->reviewTime.getValue("")); \
} \
if (query->createTime) { \
	sql << " AND create_time=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->createTime.getValue("")); \
} \
if (query->state) { \
	sql << " AND state=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->state.getValue(0)); \
} \
if (query->personName) { \
	sql << " AND person_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->personName.getValue("")); \
} \
if (query->hazardFactorCode) { \
	sql << " AND hazard_factor_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->hazardFactorCode.getValue("")); \
}

// 统计数据条数
uint64_t ReviewDAO::count(const ReviewQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM (SELECT b.person_name,a.check_project_name,a.review_explain,a.review_time,a.create_time,a.state,b.hazard_factor_code FROM t_review_record AS a JOIN t_review_person AS b ON a.person_id = b.id) AS result_set";
	REVIEW_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
// 分页查询数据  现在可以通过姓名查询数据，但不能进行模糊查询
list<ReviewDO> ReviewDAO::selectWithPage(const ReviewQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT b.person_name,a.check_project_name,a.review_explain,a.review_time,a.create_time,a.state,b.hazard_factor_code FROM t_review_record AS a JOIN t_review_person AS b ON a.person_id = b.id";
	REVIEW_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ReviewMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ReviewDO, ReviewMapper>(sqlStr, mapper, params);
}
// pdf使用 通过姓名查询数据
list<ReviewDO> ReviewDAO::selectByName(const string& name)
{
	string sql = "SELECT b.person_name,a.check_project_name,a.review_explain,a.review_time,a.create_time,a.state,b.hazard_factor_code FROM t_review_record AS a JOIN t_review_person AS b ON a.person_id = b.id WHERE b.person_name LIKE CONCAT('%',?,'%')"; 
	ReviewMapper mapper;
	return sqlSession->executeQuery<ReviewDO, ReviewMapper>(sql, mapper, "%s", name);
}
// 修改数据  下面代码不能同时修改多个表中的数据
int ReviewDAO::update(const ReviewDO& uObj)
{
	//person_name  hazard_factor_code不在该表中，无法修改  swagger上显示的这两个字段，可以直接无视
	string sql = "UPDATE `t_review_record` SET `person_id`=?,`check_project_id`=?, `check_project_name`=?, `review_explain`=?, `review_time`=?, `create_time`=?, `state`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%i%s", uObj.getPersonId(), uObj.getCheckProjectId(), uObj.getCheckProjectName(), uObj.getReviewExplain(), uObj.getReviewTime(), uObj.getCreateTime(), uObj.getState(), uObj.getId());

}
// 通过ID删除数据
int ReviewDAO::deleteById(string id)
{
	string sql = "DELETE FROM `t_review_record` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}
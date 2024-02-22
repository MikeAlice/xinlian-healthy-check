#include "stdafx.h"
#include "ReportStatisticsDAO.h"
#include "ReportStatisticsMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE unit_id in (select group_unit_id from t_group_order where order_code = ?)";\
SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue("")); \


uint64_t ReportStatisticsDAO::countPhysicalExaminationPersonnel(const ReportStatisticsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

uint64_t ReportStatisticsDAO::countReviewPersonnel(const ReportStatisticsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_review_person";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

uint64_t ReportStatisticsDAO::countReviewResults(const ReportStatisticsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_review_person";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<PhysicalExaminationPersonnelDO> ReportStatisticsDAO::selectWithPhysicalExaminationPersonnelPage(const ReportStatisticsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select t1.order_id,person_name,mobile,sex,age,id_card,department,date(check_date),physical_type,check_result,handle_opinion from t_group_person t1,t_inspection_record t2 ";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << "and t1.id=t2.person_id";
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	PhysicalExaminationPersonnelMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PhysicalExaminationPersonnelDO, PhysicalExaminationPersonnelMapper>(sqlStr, mapper, params);
}

list<ReviewPersonnelDO> ReportStatisticsDAO::selectWithReviewPersonnelPage(const ReportStatisticsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select t1.order_id,t1.person_name,t1.mobile,sex,age,t1.id_card,date(check_date),t1.physical_type,reason,check_project_name from t_group_person t1,t_review_person t2,t_review_project t3,t_review_record t4";
	SqlParams params; 
	sql << " WHERE t1.unit_id in (select group_unit_id from t_group_order where order_code = ?)"; 
	SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue("")); 
	sql << "and t1.id_card=t2.id_card and t1.id=t3.person_id and t1.id=t4.person_id";
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ReviewPersonnelMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ReviewPersonnelDO, ReviewPersonnelMapper>(sqlStr, mapper, params);
}

list<ReviewResultsDO> ReportStatisticsDAO::selectWithReviewResultsPage(const ReportStatisticsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select t1.order_id,t1.person_name,t1.mobile,sex,age,t1.id_card,t1.hazard_factors_text,t1.work_type_text,t3.work_year,date(check_date),t1.physical_type,review_result,review_opinion from t_group_person t1,t_inspection_record t2,t_interrogation t3";
	SqlParams params;
	sql << " WHERE t1.unit_id in (select group_unit_id from t_group_order where order_code = ?)";
	SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue(""));
	sql << "and t1.id=t2.person_id and t1.id=t3.person_id";
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ReviewResultsMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ReviewResultsDO, ReviewResultsMapper>(sqlStr, mapper, params);
}



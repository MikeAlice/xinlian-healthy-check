#include "stdafx.h"
#include "InfoListDAO.h"
#include "InfoListMapper.h"

#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id) { \
	sql << " AND `id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->id.getValue(0)); \
} \
if (query->personId) { \
	sql << " AND `person_id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->personId.getValue(0)); \
} \
if (query->inspectionDoctor) { \
	sql << " AND inspection_doctor=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->inspectionDoctor.getValue("")); \
} \
if (query->inspectionDate) { \
	sql << " AND inspection_date=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->inspectionDate.getValue("")); \
} \
if (query->medicalAdvice) { \
	sql << " AND medical_advice=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->medicalAdvice.getValue("")); \
} \
if (query->handleOpinion) { \
	sql << " AND handle_opinion=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->handleOpinion.getValue("")); \
}




uint64_t InfoListDAO::count(const InfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_inspection_record";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<InfoListDO> InfoListDAO::selectWithPage(const InfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT id,person_id,inspection_doctor,inspection_date,medical_advice,handle_opinion FROM t_inspection_record";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	InfoListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<InfoListDO, InfoListMapper>(sqlStr, mapper, params);
}

list<InfoListDO> InfoListDAO::selectByName(const string& name)
{
    return list<InfoListDO>();
}

uint64_t InfoListDAO::insert(const InfoListDO& iObj)
{
	string sql = "INSERT INTO `t_inspection_record` (`id`, `person_id`, `inspection_doctor`, `inspection_date`, `medical_advice`, `handle_opinion`) VALUES (?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%i%i%s%s%s%s",iObj.getId(), iObj.getPersonId(), iObj.getInspectionDoctor(), iObj.getInspectionDate(), iObj.getMedicalAdvice(), iObj.getHandleOpinion());
}

int InfoListDAO::update(const InfoListDO& uObj)
{
    return 0;
}

int InfoListDAO::deleteById(uint64_t id)
{
    return 0;
}

/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "InquiryDetailDAO.h"
#include "InquiryDetailMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
    SqlParams params; \
    if (query->id) { \
        sql << " AND a.id=?"; \
        SQLPARAMS_PUSH(params, "i", int, query->id.getValue(0)); \
    } \
    if (query->workYear) { \
        sql << " AND work_year=?"; \
        SQLPARAMS_PUSH(params, "i", int, query->workYear.getValue(0)); \
    } \
    if (query->workMonth) { \
        sql << " AND work_month=?"; \
        SQLPARAMS_PUSH(params, "i",  int, query->workMonth.getValue(0)); \
    } \
    if (query->isMarry) { \
        sql << " AND is_marry=?"; \
        SQLPARAMS_PUSH(params, "s", std::string, query->isMarry.getValue("")); \
    } \
    if (query->exposureWorkYear) { \
        sql << " AND exposure_work_year=?"; \
        SQLPARAMS_PUSH(params, "i", int, query->exposureWorkYear.getValue(0)); \
    } \
    if (query->exposureWorkMonth) { \
        sql << " AND exposure_work_month=?"; \
        SQLPARAMS_PUSH(params, "i", int, query->exposureWorkMonth.getValue(0)); \
    } \
    if (query->education) { \
        sql << " AND education=?"; \
        SQLPARAMS_PUSH(params, "s", std::string, query->education.getValue("")); \
    } \
    if (query->familyAddress) { \
        sql << " AND family_address=?"; \
        SQLPARAMS_PUSH(params, "s", std::string, query->familyAddress.getValue("")); \
    } \
    if (query->workTypeText) { \
        sql << " AND work_type_text=?"; \
        SQLPARAMS_PUSH(params, "s", std::string, query->workTypeText.getValue("")); \
    } \
    if (query->workName) { \
        sql << " AND work_name=?"; \
        SQLPARAMS_PUSH(params, "s", std::string, query->workName.getValue("")); \
    } \
    if (query->department) { \
        sql << " AND department=?"; \
        SQLPARAMS_PUSH(params, "s", std::string, query->department.getValue("")); \
    } 


uint64_t InquiryDetailDAO::count(const InquiryDetailQuery::Wrapper & query)
{
    stringstream sql; 
    sql << "SELECT COUNT(*) FROM t_group_person AS a JOIN t_interrogation AS b ON a.id = b.id";
    SAMPLE_TERAM_PARSE(query, sql);
    string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}


list<InquiryDetailDO> InquiryDetailDAO::selectWithPage(const InquiryDetailQuery::Wrapper & query)
{
    stringstream sql;
    sql << "SELECT a.id, b.work_year, b.work_month, a.is_marry, b.exposure_work_year, b.exposure_work_month, b.education, b.family_address, a.work_type_text, a.work_name, a.department FROM t_group_person AS a JOIN t_interrogation AS b ON a.id = b.id";
    SAMPLE_TERAM_PARSE(query, sql);
    sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
    InquiryDetailMapper mapper;
    string sqlStr = sql.str();
    return sqlSession->executeQuery<InquiryDetailDO, InquiryDetailMapper>(sqlStr, mapper, params);
}


int InquiryDetailDAO::update(const InquiryDetailDO& uObj)
{
    string sql = "UPDATE `t_interrogation` AS `b`, `t_group_person` AS `a` SET `b`.`work_year` = ?, `b`.`work_month` = ?, `a`.`is_marry` = ?, `b`.`exposure_work_year` = ?, `b`.`exposure_work_month` = ?, `b`.`education` = ?, `b`.`family_address` = ?, `a`.`work_type_text` = ?, `a`.`work_name` = ?, `a`.`department` = ? WHERE `a`.`id` = ? && `b`.`id` = ?";

    return sqlSession->executeUpdate(sql,"%i%i%s%i%i%s%s%s%s%s%i%i", uObj.getWorkYear(), uObj.getWorkMonth(), uObj.getIsMarry(), uObj.getExposureWorkYear(), uObj.getExposureWorkMonth(), uObj.getEducation(), uObj.getFamilyAddress(), uObj.getWorkTypeText(), uObj.getWorkName(), uObj.getDepartment(),uObj.getId(), uObj.getId());
}


list<InquiryDetailDO> InquiryDetailDAO::selectById(const string& id)
{
    string sql = "SELECT a.id, b.work_year, b.work_month, a.is_marry, b.exposure_work_year, b.exposure_work_month, b.education, b.family_address, a.work_type_text, a.work_name, a.department FROM t_group_person AS a JOIN t_interrogation AS b ON a.id = b.id WHERE a.id LIKE CONCAT('%', ? ,'%')";
    InquiryDetailMapper mapper;
    return sqlSession->executeQuery<InquiryDetailDO, InquiryDetailMapper>(sql, mapper, "%s", id);
}
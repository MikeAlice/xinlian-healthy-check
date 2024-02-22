#pragma once

#ifndef _REPORTSTATISTICSDTO_
#define _REPORTSTATISTICSDTO_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 体检人员汇总表数据实体
*/

class PhysicalExaminationPersonnelDTO : public oatpp::DTO
{
	//定义初始化
	DTO_INIT(PhysicalExaminationPersonnelDTO, DTO);
	//编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unitreport.summaryTable.number"));
	//姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("unitreport.summaryTable.personName"));
	//手机号
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("unitreport.summaryTable.mobile"));
	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("unitreport.summaryTable.sex"));
	//年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("unitreport.summaryTable.age"));
	//身份证号码
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("unitreport.summaryTable.idCard"));
	//所属部门
	API_DTO_FIELD_DEFAULT(String, department, ZH_WORDS_GETTER("unitreport.summaryTable.department"));
	//体检时间
	API_DTO_FIELD_DEFAULT(String, physicalDate, ZH_WORDS_GETTER("unitreport.summaryTable.physicalDate"));
	//体检类别
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unitreport.summaryTable.physicalType"));
	//是否正常
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("unitreport.summaryTable.status"));
	//体检结果
	API_DTO_FIELD_DEFAULT(String, checkRusult, ZH_WORDS_GETTER("unitreport.summaryTable.checkRusult"));
	//处理意见
	API_DTO_FIELD_DEFAULT(String, concludingObservations, ZH_WORDS_GETTER("unitreport.summaryTable.concludingObservations"));
};

class PhysicalExaminationPersonnelPageDTO : public PageDTO< PhysicalExaminationPersonnelDTO::Wrapper>
{
	//定义初始化
	DTO_INIT(PhysicalExaminationPersonnelPageDTO, PageDTO<PhysicalExaminationPersonnelDTO::Wrapper>);
};
/*
* 复查人员汇总表数据实体
*/

class ReviewPersonnelDTO : public oatpp::DTO
{
	//定义初始化
	DTO_INIT(ReviewPersonnelDTO, DTO);
	//编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unitreport.summaryTable.number"));
	//姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("unitreport.summaryTable.personName"));
	//手机号
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("unitreport.summaryTable.mobile"));
	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("unitreport.summaryTable.sex"));
	//年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("unitreport.summaryTable.age"));
	//身份证号码
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("unitreport.summaryTable.idCard"));
	//体检时间
	API_DTO_FIELD_DEFAULT(String, physicalDate, ZH_WORDS_GETTER("unitreport.summaryTable.physicalDate"));
	//体检类别
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unitreport.summaryTable.physicalType"));
	//复查原因
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("unitreport.summaryTable.reason"));
	//复查项目
	API_DTO_FIELD_DEFAULT(String, checkProjectName, ZH_WORDS_GETTER("unitreport.summaryTable.checkProjectName"));
};

class ReviewPersonnelPageDTO : public PageDTO< ReviewPersonnelDTO::Wrapper>
{
	//定义初始化
	DTO_INIT(ReviewPersonnelPageDTO, PageDTO<ReviewPersonnelDTO::Wrapper>);
};
/*
* 复查结果汇总表数据实体
*/

class ReviewResultsDTO : public oatpp::DTO
{
	//定义初始化
	DTO_INIT(ReviewResultsDTO, DTO);
	//编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unitreport.summaryTable.number"));
	//姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("unitreport.summaryTable.personName"));
	//手机号
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("unitreport.summaryTable.mobile"));
	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("unitreport.summaryTable.sex"));
	//年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("unitreport.summaryTable.age"));
	//身份证号码
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("unitreport.summaryTable.idCard"));
	//危险因素
	API_DTO_FIELD_DEFAULT(String, hazardFactorCode, ZH_WORDS_GETTER("unitreport.summaryTable.hazardFactorCode"));
	//工种
	API_DTO_FIELD_DEFAULT(String, workTypeText, ZH_WORDS_GETTER("unitreport.summaryTable.hazardFactorCode"));
	//接触有害工龄（年）
	API_DTO_FIELD_DEFAULT(UInt32, ExposureToHarmfulWorkExperience, ZH_WORDS_GETTER("unitreport.summaryTable.ExposureToHarmfulWorkExperience"));
	//体检时间
	API_DTO_FIELD_DEFAULT(String, physicalDate, ZH_WORDS_GETTER("unitreport.summaryTable.physicalDate"));
	//体检类型
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unitreport.summaryTable.physicalType"));
	//复查体检结果
	API_DTO_FIELD_DEFAULT(String, checkRusult, ZH_WORDS_GETTER("unitreport.summaryTable.checkRusult"));
	//复查处理意见
	API_DTO_FIELD_DEFAULT(String, concludingObservations, ZH_WORDS_GETTER("unitreport.summaryTable.concludingObservations"));
};

class ReviewResultsPageDTO : public PageDTO< ReviewResultsDTO::Wrapper>
{
	//定义初始化
	DTO_INIT(ReviewResultsPageDTO, PageDTO<ReviewResultsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif
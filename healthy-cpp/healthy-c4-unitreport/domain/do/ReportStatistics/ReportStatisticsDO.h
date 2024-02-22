#pragma once

#ifndef _REPORTSTATISTICS_DO_
#define _REPORTSTATISTICS_DO_

#include "../DoInclude.h"

/**
 * 查询单位列表数据库实体类
 */
class PhysicalExaminationPersonnelDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, personName, PersonName);
	// 手机号
	CC_SYNTHESIZE(string, mobile, Mobile);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 身份证号码
	CC_SYNTHESIZE(string, idCard, IdCard);
	// 所属部门
	CC_SYNTHESIZE(string, department, Department);
	// 体检时间
	CC_SYNTHESIZE(string, physicalDate, PhysicalDate);
	// 体检类别
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// 体检结果
	CC_SYNTHESIZE(int, checkRusult, CheckRusult);
	// 处理意见
	CC_SYNTHESIZE(string, concludingObservations, ConcludingObservations);
public:
	PhysicalExaminationPersonnelDO()
	{
		id = "";
		personName = "";
		mobile = "";
		sex = "";
		idCard = "";
		department = "";
		physicalDate = "";
		physicalType = "";

	}
};

class ReviewPersonnelDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, personName, PersonName);
	// 手机号
	CC_SYNTHESIZE(string, mobile, Mobile);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 身份证号码
	CC_SYNTHESIZE(string, idCard, IdCard);
	// 体检时间
	CC_SYNTHESIZE(string, physicalDate, PhysicalDate);
	// 体检类别
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// 复查原因
	CC_SYNTHESIZE(string, reason, Reason);
	// 复查项目
	CC_SYNTHESIZE(string, checkProjectName, CheckProjectName);
public:
	ReviewPersonnelDO()
	{
		id = "";
		personName = "";
		mobile = "";
		sex = "";
		idCard = "";
		physicalDate = "";
		reason = "";
		checkProjectName = "";
	}
};

class ReviewResultsDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, personName, PersonName);
	// 手机号
	CC_SYNTHESIZE(string, mobile, Mobile);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 身份证号码
	CC_SYNTHESIZE(string, idCard, IdCard);
	// 危险因素
	CC_SYNTHESIZE(string, hazardFactorCode, HazardFactorCode);
	// 工种
	CC_SYNTHESIZE(string, workTypeText, WorkTypeText);
	// 接触有害工龄（年）
	CC_SYNTHESIZE(int, ExposureToHarmfulWorkExperience, ExposureToHarmfulWorkExperience);
	// 体检时间
	CC_SYNTHESIZE(string, physicalDate, PhysicalDate);
	// 体检类别
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// 复查体检结果
	CC_SYNTHESIZE(string, checkRusult, CheckRusult);
	// 复查处理意见
	CC_SYNTHESIZE(string, concludingObservations, ConcludingObservations);
public:
	ReviewResultsDO()
	{
		id = "";
		personName = "";
		mobile = "";
		sex = "";
		idCard = "";
		hazardFactorCode = "";
		workTypeText = "";
		physicalDate = "";
		physicalType = "";
		concludingObservations = "";
	}
};

#endif // !_SAMPLE_DO_
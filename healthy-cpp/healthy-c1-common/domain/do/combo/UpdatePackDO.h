#pragma once

#ifndef _UPDATEPACKDO_H
#define _UPDATEPACKDO_H
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class UpdatePackDO
{
	// 主键
	CC_SYNTHESIZE(string, id, Id);
	// 套餐名称
	CC_SYNTHESIZE(string, name, Name);
	// 封面图片地址
	CC_SYNTHESIZE(string, url, Url);
	// 套餐类型
	CC_SYNTHESIZE(string, type, Type);
	// 简拼
	CC_SYNTHESIZE(string, simpleSpell, SimpleSpell);
	// 适用性别
	CC_SYNTHESIZE(string, fitSex, FitSex);
	// 排序号
	CC_SYNTHESIZE(int, orderNum, OrderNum);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 职业阶段
	CC_SYNTHESIZE(string, careerStage, CareerStage);
	// 危害因素编码
	CC_SYNTHESIZE(string, hazardFactors, HazardFactors);
	// 危害因素文本
	CC_SYNTHESIZE(string, hazardFactorsText, HazardFactorsText);
	// 职业病
	CC_SYNTHESIZE(string, occupationalDiseases, OccupationalDiseases);
	// 职业禁忌
	CC_SYNTHESIZE(string, occupationalTaboo, OccupationalTaboo);
	// 职业病编码
	CC_SYNTHESIZE(string, occupationalDiseasesCode, OccupationalDiseasesCode);
	// 职业禁忌编码
	CC_SYNTHESIZE(string, occupationalTabooCode, OccupationalTabooCode);
	// 诊断标准
	CC_SYNTHESIZE(string, diagnosticCriteria, DiagnosticCriteria);
	// 症状询问
	CC_SYNTHESIZE(string, symptomInquiry, SymptomInquiry);

public:
	UpdatePackDO() {
		id = "";
		name = "";
		url = "";
		type = "";
		simpleSpell = "";
		fitSex = "";
		orderNum = -1;
		remark = "";
		careerStage = "";
		hazardFactors = "";
		hazardFactorsText = "";
		occupationalDiseases = "";
		occupationalTaboo = "";
		occupationalDiseasesCode = "";
		occupationalTabooCode = "";
		diagnosticCriteria = "";
		symptomInquiry = "";
	}
}; 
#endif // _UPDATEPACKDO_H
#pragma once
#ifndef _PREVIEWREPORT_DO_
#define _PREVIEWREPORT_DO_
#include "../DoInclude.h"

/**
 * 报告预览数据库实体类
 * 负责人：小智
 */
class PreviewReportDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(uint32_t, age, Age);
	// 身份证号
	CC_SYNTHESIZE(string, idCard, IdCard);
	// 联系电话
	CC_SYNTHESIZE(string, mobile, Mobile);
	// 体检类型
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// 工作单位
	CC_SYNTHESIZE(string, dept, Dept);
	// 结论
	CC_SYNTHESIZE(string, conclusion, Conclusion);
	// 处理意见
	CC_SYNTHESIZE(string, handleOpinion, HandleOpinion);
	// 主检医生
	CC_SYNTHESIZE(string, inspectionDoctor, InspectionDoctor);
	// 体检日期
	CC_SYNTHESIZE(string, inspectionDate, InspectionDate);
	// 体检单位
	 CC_SYNTHESIZE(string, diagnosticUnit, DiagnosticUnit);
	// PDF地址
	CC_SYNTHESIZE(string, href, Href);


public:
	PreviewReportDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
		idCard = "";
		mobile = "";
		physicalType = "";
		dept = "";
		conclusion = "";
		handleOpinion = "";
		inspectionDoctor = "";
		inspectionDate = "";
		diagnosticUnit = "";
		href = "";
	}
};

#endif // !_PREVIEWREPORT_DO_

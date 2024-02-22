#pragma once
#ifndef _PREVIEWREPORT_DO_
#define _PREVIEWREPORT_DO_
#include "../DoInclude.h"

/**
 * 报告审核数据库实体类
 * 负责人Z
 */
class PreviewReportDO
{
	// 唯一编号
	CC_SYNTHESIZE(string, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, person_name, Person_name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 身份证号
	CC_SYNTHESIZE(string, id_card, Id_card);
	// 联系电话
	CC_SYNTHESIZE(string, mobile, Mobile);
	// 体检种类
	CC_SYNTHESIZE(string, physical_type, Physical_type);
	// 工作单位
	CC_SYNTHESIZE(string, dept, Dept);
	// 总检日期
	CC_SYNTHESIZE(string, inspection_date, Inspection_date);
	// 健康检查结论
	CC_SYNTHESIZE(string, conclusion, Conclusion);
	// 处理意见
	CC_SYNTHESIZE(string, handle_opinion, Handle_opinion);
	// 主检医师
	CC_SYNTHESIZE(string, inspection_doctor, Inspection_doctor);
	// 检查单位
	CC_SYNTHESIZE(string, diagnostic_unit, Diagnostic_unit);
public:
	PreviewReportDO() {
		id = "";
		person_name = "";
		sex = "";
		age = -1;
		id_card = "";
		mobile = "";
		physical_type = "";
		dept = "";
		conclusion = "";
		handle_opinion = "";
		inspection_doctor = "";
		inspection_date = "";
		diagnostic_unit = "";
	}
};

#endif // !_PREVIEWREPORT_DO_

#pragma once

#ifndef _HEALTH_CERTIFICATE_LIST_DO_
#define _HEALTH_CERTIFICATE_LIST_DO_
#include "../DoInclude.h"

/**
 * 报告列表数据库实体类
 */
class HealthCertificateListDO
{
	// 健康证编码
	CC_SYNTHESIZE(string, health_ccertificate, Health_ccertificate);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 有效日期
	CC_SYNTHESIZE(string, term_of_validity, Term_of_validity);
	// 发证单位
	CC_SYNTHESIZE(string, unit_of_issue, Unit_of_issue);
	// 打印状态
	CC_SYNTHESIZE(int, print_state, Print_state);
	// 上传状态
	CC_SYNTHESIZE(int, is_upload, Is_upload);
public:
	HealthCertificateListDO() {
		health_ccertificate = "";
		name = "";
		sex = "";
		age = 0;
		term_of_validity = "";
		unit_of_issue = "";
		print_state = 0;
		is_upload = 0;
	}
};
#endif
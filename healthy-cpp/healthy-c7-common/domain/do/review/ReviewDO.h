#pragma once
#ifndef _REVIEW_DO_
#define _REVIEW_DO_
#include "../DoInclude.h"

/**
 * 复查记录数据库实体类
 */
class ReviewDO
{
	// 唯一编号 id varchar(50)
	CC_SYNTHESIZE(string, id, Id);
	// 姓名 person_id varchar(50)    t_review_person中有person_name
	CC_SYNTHESIZE(string, personId, PersonId);
	CC_SYNTHESIZE(string, personName, PersonName);
	//复查项目check_project_id varchar(50)   check_project_name varchar(255)
	CC_SYNTHESIZE(string, checkProjectId, CheckProjectId);
	CC_SYNTHESIZE(string, checkProjectName, CheckProjectName);
	//复查说明review_explain varchar(255)
	CC_SYNTHESIZE(string, reviewExplain, ReviewExplain);
	//操作日期review_time datetime '复查日期'
	CC_SYNTHESIZE(string, reviewTime, ReviewTime);
	//登记日期create_time datetime '创建日期'
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//登记状态state int 审核状态
	CC_SYNTHESIZE(int, state, State);
	//危害因素hazard_factor_code varchar(255)   t_review_person中有hazard_factor_code
	CC_SYNTHESIZE(string, hazardFactorCode, HazardFactorCode);
	//操作
	
	// PDF地址
	CC_SYNTHESIZE(string, downloadUrl, downloadUrl);

public:
	ReviewDO() {
		id = "";
		personId = "";
		personName = "";
		checkProjectId = "";
		checkProjectName = "";
		reviewExplain = "";
		reviewTime = "";
		createTime = "";
		state = 0;
		hazardFactorCode = "";
		downloadUrl = "";
	}
};

#endif // !_REVIEW_DO_
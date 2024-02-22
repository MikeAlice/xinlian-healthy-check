#pragma once
#ifndef _REVIEW_DO_
#define _REVIEW_DO_
#include "../DoInclude.h"

/**
 * �����¼���ݿ�ʵ����
 */
class ReviewDO
{
	// Ψһ��� id varchar(50)
	CC_SYNTHESIZE(string, id, Id);
	// ���� person_id varchar(50)    t_review_person����person_name
	CC_SYNTHESIZE(string, personId, PersonId);
	CC_SYNTHESIZE(string, personName, PersonName);
	//������Ŀcheck_project_id varchar(50)   check_project_name varchar(255)
	CC_SYNTHESIZE(string, checkProjectId, CheckProjectId);
	CC_SYNTHESIZE(string, checkProjectName, CheckProjectName);
	//����˵��review_explain varchar(255)
	CC_SYNTHESIZE(string, reviewExplain, ReviewExplain);
	//��������review_time datetime '��������'
	CC_SYNTHESIZE(string, reviewTime, ReviewTime);
	//�Ǽ�����create_time datetime '��������'
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//�Ǽ�״̬state int ���״̬
	CC_SYNTHESIZE(int, state, State);
	//Σ������hazard_factor_code varchar(255)   t_review_person����hazard_factor_code
	CC_SYNTHESIZE(string, hazardFactorCode, HazardFactorCode);
	//����
	
	// PDF��ַ
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
#pragma once
#ifndef _INTERRO_DO_
#define _INTERRO_DO_
#include"../DoInclude.h"

/**
* 数据库实体类
*/
class InterroDO
{
	// 类别
	CC_SYNTHESIZE(string, type, Type);
	// 体检项目
	CC_SYNTHESIZE(string, project, Project);
	// 项目编号
	CC_SYNTHESIZE (string, code, Code);
	// 危机程度
	CC_SYNTHESIZE(string, degree, Degree);
	// 病程时间
	CC_SYNTHESIZE(string, coursetime, Coursetime);
	// 人员编号主键
	CC_SYNTHESIZE(string, personid, Personid);
	// 创建人-体检医生
	CC_SYNTHESIZE(string, createid, Createid);
	//检查医生
	CC_SYNTHESIZE(string, createname, Createname);

public:
	InterroDO() {
		// id = "";
		type = "";
		project = "";
		code = "";
		degree = "";
		coursetime = "";
		personid = "";
		createid = "";
		createname = "";
		//createtime = "";
	}
};

#endif //_INTERRO_DO_

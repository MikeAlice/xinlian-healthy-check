#pragma once
#ifndef _INTERRO_DO_
#define _INTERRO_DO_
#include"../DoInclude.h"

/**
* ���ݿ�ʵ����
*/
class InterroDO
{
	// ���
	CC_SYNTHESIZE(string, type, Type);
	// �����Ŀ
	CC_SYNTHESIZE(string, project, Project);
	// ��Ŀ���
	CC_SYNTHESIZE (string, code, Code);
	// Σ���̶�
	CC_SYNTHESIZE(string, degree, Degree);
	// ����ʱ��
	CC_SYNTHESIZE(string, coursetime, Coursetime);
	// ��Ա�������
	CC_SYNTHESIZE(string, personid, Personid);
	// ������-���ҽ��
	CC_SYNTHESIZE(string, createid, Createid);
	//���ҽ��
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

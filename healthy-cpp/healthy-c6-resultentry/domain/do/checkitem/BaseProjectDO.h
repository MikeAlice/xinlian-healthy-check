#pragma once
#ifndef _BASEPROJECT_DO_
#define _BASEPROJECT_DO_

#include "../DoInclude.h"

class BaseProjectDO {

	//��Ŀ����
	CC_SYNTHESIZE(string, code, Code);
	//�����Ŀ
	CC_SYNTHESIZE(string, name, Name);
	//��λ
	CC_SYNTHESIZE(string, unit_name, Unit_name);
	//�ο�ֵ
	CC_SYNTHESIZE(string, healthy_value, Healthy_value);
	//Ĭ��ֵ
	CC_SYNTHESIZE(string, default_value, Default_value);
	//��ϸ���
	CC_SYNTHESIZE(string, result_type, Result_type);

public:
	BaseProjectDO() {
		code = "";
		name = "";
	}
};

#endif //!_BASEPROJECT_DO_

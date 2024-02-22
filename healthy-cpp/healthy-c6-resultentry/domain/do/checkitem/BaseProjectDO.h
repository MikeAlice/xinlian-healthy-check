#pragma once
#ifndef _BASEPROJECT_DO_
#define _BASEPROJECT_DO_

#include "../DoInclude.h"

class BaseProjectDO {

	//项目代码
	CC_SYNTHESIZE(string, code, Code);
	//体检项目
	CC_SYNTHESIZE(string, name, Name);
	//单位
	CC_SYNTHESIZE(string, unit_name, Unit_name);
	//参考值
	CC_SYNTHESIZE(string, healthy_value, Healthy_value);
	//默认值
	CC_SYNTHESIZE(string, default_value, Default_value);
	//明细结果
	CC_SYNTHESIZE(string, result_type, Result_type);

public:
	BaseProjectDO() {
		code = "";
		name = "";
	}
};

#endif //!_BASEPROJECT_DO_

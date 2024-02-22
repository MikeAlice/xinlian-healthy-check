#ifndef _RPPROCHECK_DO_
#define _RPPROCHECK_DO_
#include "../DoInclude.h"

/*
* 用户项目检查数据库实体类RPProCheckDO
* 开头小写为DO属性， 大写为get/set后衔接内容
*/
class RPProCheckDO
{
	//唯一id
	CC_SYNTHESIZE(string, id, Id);

	//体检人id
	CC_SYNTHESIZE(string, personId, PersonId);
	//科室id
	CC_SYNTHESIZE(string, officeId, OfficeId);
	//分组项目id
	CC_SYNTHESIZE(string, groupItemId, GroupItemId);
	// '状态  1已登记  2弃检'
	CC_SYNTHESIZE(int, state, State);
	


public:
	RPProCheckDO()
		: id(""),
		personId(""),
		officeId(""),
		groupItemId(""),
		state(1)
	{
		// 这里将类中的各个成员变量初始化为合适的默认值
		// 如果有其他默认值或者初始化逻辑，请根据实际情况进行修改
	}

};




#endif // !_RPPROCHECK_DO_

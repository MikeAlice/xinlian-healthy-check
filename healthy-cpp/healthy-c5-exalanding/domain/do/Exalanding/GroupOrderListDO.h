#ifndef _GROUP_ORDER_LIST_DO_
#define _GROUP_ORDER_LIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class GroupOrderListDO
{
	//性别
	CC_SYNTHESIZE(string, sex, Sex);
	//单位名称
	CC_SYNTHESIZE(string, groupUnitName, GroupUnitName);
	//分组名称
	CC_SYNTHESIZE(string, groupName, GroupName);
public:
	GroupOrderListDO() {
		sex = "男";
		groupUnitName="";
		groupName = "";
	}
};

#endif // !_GROUP_ORDER_LIST_DO_
#ifndef _GROUP_ORDER_LIST_DO_
#define _GROUP_ORDER_LIST_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class GroupOrderListDO
{
	//�Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	//��λ����
	CC_SYNTHESIZE(string, groupUnitName, GroupUnitName);
	//��������
	CC_SYNTHESIZE(string, groupName, GroupName);
public:
	GroupOrderListDO() {
		sex = "��";
		groupUnitName="";
		groupName = "";
	}
};

#endif // !_GROUP_ORDER_LIST_DO_
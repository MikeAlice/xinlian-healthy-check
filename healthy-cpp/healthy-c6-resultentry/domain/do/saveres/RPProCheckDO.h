#ifndef _RPPROCHECK_DO_
#define _RPPROCHECK_DO_
#include "../DoInclude.h"

/*
* �û���Ŀ������ݿ�ʵ����RPProCheckDO
* ��ͷСдΪDO���ԣ� ��дΪget/set���ν�����
*/
class RPProCheckDO
{
	//Ψһid
	CC_SYNTHESIZE(string, id, Id);

	//�����id
	CC_SYNTHESIZE(string, personId, PersonId);
	//����id
	CC_SYNTHESIZE(string, officeId, OfficeId);
	//������Ŀid
	CC_SYNTHESIZE(string, groupItemId, GroupItemId);
	// '״̬  1�ѵǼ�  2����'
	CC_SYNTHESIZE(int, state, State);
	


public:
	RPProCheckDO()
		: id(""),
		personId(""),
		officeId(""),
		groupItemId(""),
		state(1)
	{
		// ���ｫ���еĸ�����Ա������ʼ��Ϊ���ʵ�Ĭ��ֵ
		// ���������Ĭ��ֵ���߳�ʼ���߼��������ʵ����������޸�
	}

};




#endif // !_RPPROCHECK_DO_

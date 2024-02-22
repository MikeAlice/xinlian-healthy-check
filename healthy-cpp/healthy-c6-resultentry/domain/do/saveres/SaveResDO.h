#ifndef _SaveRes_DO_
#define _SaveRes_DO_
#include "../DoInclude.h"

/*
* ��̨������ݿ�ʵ����SaveResDO
* ��ͷСдΪDO����
*/
class SaveResDO
{
	//Ψһid
	CC_SYNTHESIZE(string, id,Id);

	//�����id
	CC_SYNTHESIZE(string, personId, PersonId);
	//����id
	CC_SYNTHESIZE(string, officeId, OfficeId);
	//��������
	CC_SYNTHESIZE(string, officeName, OfficeName);
	//���ҽ��
	CC_SYNTHESIZE(string, checkDoc, CheckDoc);
	//�������
	CC_SYNTHESIZE(string, checkDate, CheckDate);
	// del flag
	CC_SYNTHESIZE(int, delFlag, DelFlag);
	//������Ŀid
	CC_SYNTHESIZE(string, groupItemId, GroupItemId);
	//������Ŀ����
	CC_SYNTHESIZE(string, groupItemName, GroupItemName);
	//���С��
	CC_SYNTHESIZE(string, diagnoseSum, DiagnoseSum);
	//�Ƿ񸴲�(0��1�ǣ�
	CC_SYNTHESIZE(int, isCheck, IsCheck);
	//createId
	CC_SYNTHESIZE(string, createId, CreateId);
	//createDate
	CC_SYNTHESIZE(string, createDate, CreateDate);
	//updateId
	CC_SYNTHESIZE(string, updateId, UpdateId);
	//updateDate
	CC_SYNTHESIZE(string, updateDate, UpdateDate);

	
	
	// depart res ����
	//�������
	CC_SYNTHESIZE(string, diagnoseTip, DiagnoseTip);
	// ������
	CC_SYNTHESIZE(int, check_num, Check_num);
	// ���״̬(0-һ�㣬1-����)
	CC_SYNTHESIZE(int, state, State);
	// �Ƿ�Ϊ����
	CC_SYNTHESIZE(string, isFile, IsFile);


	// item depart res ����

	// �����Ļ�����Ŀid
	CC_SYNTHESIZE(string, orderGroupItemProjectId, OrderGroupItemProjectId);
	// �����Ļ�����Ŀ����
	CC_SYNTHESIZE(string, orderGroupItemProjectName, OrderGroupItemProjectName);
	// �����
	CC_SYNTHESIZE(string, result, Result);
	// ������λ����
	CC_SYNTHESIZE(string, unitCode, UnitCode);
	// ������λ����
	CC_SYNTHESIZE(string, unitName, UnitName);
	// �Ƿ�����쳣��1-��2-�ǣ�
	CC_SYNTHESIZE(int, ignoreStatus, IgnoreStatus);
	// Σ���̶�
	CC_SYNTHESIZE(string, crisisDegree, CrisisDegree);
	// ����
	CC_SYNTHESIZE(int, positive, Positive);
	// depart res ��id
	CC_SYNTHESIZE(string, departResId, DepartResId);
	// ����num
	CC_SYNTHESIZE(int, orderNum, OrderNum);


public:
	SaveResDO()
		: id(""),
		personId(""),
		officeId(""),
		officeName(""),
		checkDoc(""),
		checkDate(""),
		delFlag(0),
		groupItemId(""),
		groupItemName(""),
		diagnoseSum(""),
		isCheck(0),
		createId(""),
		createDate(""),
		diagnoseTip(""),
		check_num(0),
		state(0),
		isFile(""),
		orderGroupItemProjectId(""),
		orderGroupItemProjectName(""),
		result(""),
		unitCode(""),
		unitName(""),
		ignoreStatus(0),
		crisisDegree(""),
		positive(0),
		departResId(""),
		orderNum(1)
	{
		// ���ｫ���еĸ�����Ա������ʼ��Ϊ���ʵ�Ĭ��ֵ
		// ���������Ĭ��ֵ���߳�ʼ���߼��������ʵ����������޸�
	}

};




#endif // !_SaveRes_DO_

#ifndef _REPORTDO_H_
#define _REPORTDO_H_
#include "../DoInclude.h"

/*
 * ʾ�����ݿ�ʵ����
 */
class ReportDO
{
	//������
	CC_SYNTHESIZE(string, code, Code);
	//�������
	CC_SYNTHESIZE(string, phyType, PhyType);
	//��쵥λ
	CC_SYNTHESIZE(string, phyUnit, PhyUnit);
	//ί�е�λ
	CC_SYNTHESIZE(string, enUnit, EnUnit);
	//��������
	CC_SYNTHESIZE(string, phyDate, PhyDate);
	//�������
	CC_SYNTHESIZE(int, phyNum, PhyNum);
	//Σ������
	CC_SYNTHESIZE(string, hazFactor, HazFactor);
	//�����Ŀ
	CC_SYNTHESIZE(string, phyProj, PhyProj);
	//��������
	CC_SYNTHESIZE(string, evalBasis, EvalBasis);
	//�����ۼ��������
	CC_SYNTHESIZE(string, phyConclusion, PhyConclusion);
public:
	ReportDO() {
		code = "";
		phyType = "";
		phyUnit = "";
		enUnit = "";
		phyDate = "";
		phyNum = 0;
		hazFactor = "";
		phyProj = "";
		evalBasis = "";
		phyConclusion = "";

	}
};
#endif 



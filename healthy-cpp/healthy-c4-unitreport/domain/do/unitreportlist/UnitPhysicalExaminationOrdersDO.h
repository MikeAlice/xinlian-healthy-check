#pragma once

#ifndef _UNITPHYSICALEXAMINATIONORDERS_DO_
#define _UNITPHYSICALEXAMINATIONORDERS_DO_

#include "../DoInclude.h"

/**
 * ��ѯ��λ�б����ݿ�ʵ����
 */
class UnitPhysicalExaminationOrdersDO
{
	// ��λ����
	CC_SYNTHESIZE(string, name, Name);
	// �������
	CC_SYNTHESIZE(string, code, Code);
	// ��������
	CC_SYNTHESIZE(string, signingTime, SigningTime);
	// �Ƿ��ϱ�
	CC_SYNTHESIZE(int, Escalation, Escalation);
	// �������
	CC_SYNTHESIZE(int, detectionType, DetectionType);
public:
	UnitPhysicalExaminationOrdersDO() 
	{
		name = "";
		code = "";
		signingTime = "";
	}
};

#endif // !_SAMPLE_DO_
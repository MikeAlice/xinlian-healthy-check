#pragma once

#ifndef _UPDATEPACKDO_H
#define _UPDATEPACKDO_H
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class UpdatePackDO
{
	// ����
	CC_SYNTHESIZE(string, id, Id);
	// �ײ�����
	CC_SYNTHESIZE(string, name, Name);
	// ����ͼƬ��ַ
	CC_SYNTHESIZE(string, url, Url);
	// �ײ�����
	CC_SYNTHESIZE(string, type, Type);
	// ��ƴ
	CC_SYNTHESIZE(string, simpleSpell, SimpleSpell);
	// �����Ա�
	CC_SYNTHESIZE(string, fitSex, FitSex);
	// �����
	CC_SYNTHESIZE(int, orderNum, OrderNum);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ְҵ�׶�
	CC_SYNTHESIZE(string, careerStage, CareerStage);
	// Σ�����ر���
	CC_SYNTHESIZE(string, hazardFactors, HazardFactors);
	// Σ�������ı�
	CC_SYNTHESIZE(string, hazardFactorsText, HazardFactorsText);
	// ְҵ��
	CC_SYNTHESIZE(string, occupationalDiseases, OccupationalDiseases);
	// ְҵ����
	CC_SYNTHESIZE(string, occupationalTaboo, OccupationalTaboo);
	// ְҵ������
	CC_SYNTHESIZE(string, occupationalDiseasesCode, OccupationalDiseasesCode);
	// ְҵ���ɱ���
	CC_SYNTHESIZE(string, occupationalTabooCode, OccupationalTabooCode);
	// ��ϱ�׼
	CC_SYNTHESIZE(string, diagnosticCriteria, DiagnosticCriteria);
	// ֢״ѯ��
	CC_SYNTHESIZE(string, symptomInquiry, SymptomInquiry);

public:
	UpdatePackDO() {
		id = "";
		name = "";
		url = "";
		type = "";
		simpleSpell = "";
		fitSex = "";
		orderNum = -1;
		remark = "";
		careerStage = "";
		hazardFactors = "";
		hazardFactorsText = "";
		occupationalDiseases = "";
		occupationalTaboo = "";
		occupationalDiseasesCode = "";
		occupationalTabooCode = "";
		diagnosticCriteria = "";
		symptomInquiry = "";
	}
}; 
#endif // _UPDATEPACKDO_H
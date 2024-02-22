#pragma once

#ifndef _REPORTSTATISTICS_DO_
#define _REPORTSTATISTICS_DO_

#include "../DoInclude.h"

/**
 * ��ѯ��λ�б����ݿ�ʵ����
 */
class PhysicalExaminationPersonnelDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, personName, PersonName);
	// �ֻ���
	CC_SYNTHESIZE(string, mobile, Mobile);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// ���֤����
	CC_SYNTHESIZE(string, idCard, IdCard);
	// ��������
	CC_SYNTHESIZE(string, department, Department);
	// ���ʱ��
	CC_SYNTHESIZE(string, physicalDate, PhysicalDate);
	// ������
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// �����
	CC_SYNTHESIZE(int, checkRusult, CheckRusult);
	// �������
	CC_SYNTHESIZE(string, concludingObservations, ConcludingObservations);
public:
	PhysicalExaminationPersonnelDO()
	{
		id = "";
		personName = "";
		mobile = "";
		sex = "";
		idCard = "";
		department = "";
		physicalDate = "";
		physicalType = "";

	}
};

class ReviewPersonnelDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, personName, PersonName);
	// �ֻ���
	CC_SYNTHESIZE(string, mobile, Mobile);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// ���֤����
	CC_SYNTHESIZE(string, idCard, IdCard);
	// ���ʱ��
	CC_SYNTHESIZE(string, physicalDate, PhysicalDate);
	// ������
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// ����ԭ��
	CC_SYNTHESIZE(string, reason, Reason);
	// ������Ŀ
	CC_SYNTHESIZE(string, checkProjectName, CheckProjectName);
public:
	ReviewPersonnelDO()
	{
		id = "";
		personName = "";
		mobile = "";
		sex = "";
		idCard = "";
		physicalDate = "";
		reason = "";
		checkProjectName = "";
	}
};

class ReviewResultsDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, personName, PersonName);
	// �ֻ���
	CC_SYNTHESIZE(string, mobile, Mobile);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// ���֤����
	CC_SYNTHESIZE(string, idCard, IdCard);
	// Σ������
	CC_SYNTHESIZE(string, hazardFactorCode, HazardFactorCode);
	// ����
	CC_SYNTHESIZE(string, workTypeText, WorkTypeText);
	// �Ӵ��к����䣨�꣩
	CC_SYNTHESIZE(int, ExposureToHarmfulWorkExperience, ExposureToHarmfulWorkExperience);
	// ���ʱ��
	CC_SYNTHESIZE(string, physicalDate, PhysicalDate);
	// ������
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// ���������
	CC_SYNTHESIZE(string, checkRusult, CheckRusult);
	// ���鴦�����
	CC_SYNTHESIZE(string, concludingObservations, ConcludingObservations);
public:
	ReviewResultsDO()
	{
		id = "";
		personName = "";
		mobile = "";
		sex = "";
		idCard = "";
		hazardFactorCode = "";
		workTypeText = "";
		physicalDate = "";
		physicalType = "";
		concludingObservations = "";
	}
};

#endif // !_SAMPLE_DO_
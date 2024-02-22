#pragma once

#ifndef _REPORTSTATISTICSDTO_
#define _REPORTSTATISTICSDTO_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
* �����Ա���ܱ�����ʵ��
*/

class PhysicalExaminationPersonnelDTO : public oatpp::DTO
{
	//�����ʼ��
	DTO_INIT(PhysicalExaminationPersonnelDTO, DTO);
	//���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unitreport.summaryTable.number"));
	//����
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("unitreport.summaryTable.personName"));
	//�ֻ���
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("unitreport.summaryTable.mobile"));
	//�Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("unitreport.summaryTable.sex"));
	//����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("unitreport.summaryTable.age"));
	//���֤����
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("unitreport.summaryTable.idCard"));
	//��������
	API_DTO_FIELD_DEFAULT(String, department, ZH_WORDS_GETTER("unitreport.summaryTable.department"));
	//���ʱ��
	API_DTO_FIELD_DEFAULT(String, physicalDate, ZH_WORDS_GETTER("unitreport.summaryTable.physicalDate"));
	//������
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unitreport.summaryTable.physicalType"));
	//�Ƿ�����
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("unitreport.summaryTable.status"));
	//�����
	API_DTO_FIELD_DEFAULT(String, checkRusult, ZH_WORDS_GETTER("unitreport.summaryTable.checkRusult"));
	//�������
	API_DTO_FIELD_DEFAULT(String, concludingObservations, ZH_WORDS_GETTER("unitreport.summaryTable.concludingObservations"));
};

class PhysicalExaminationPersonnelPageDTO : public PageDTO< PhysicalExaminationPersonnelDTO::Wrapper>
{
	//�����ʼ��
	DTO_INIT(PhysicalExaminationPersonnelPageDTO, PageDTO<PhysicalExaminationPersonnelDTO::Wrapper>);
};
/*
* ������Ա���ܱ�����ʵ��
*/

class ReviewPersonnelDTO : public oatpp::DTO
{
	//�����ʼ��
	DTO_INIT(ReviewPersonnelDTO, DTO);
	//���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unitreport.summaryTable.number"));
	//����
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("unitreport.summaryTable.personName"));
	//�ֻ���
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("unitreport.summaryTable.mobile"));
	//�Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("unitreport.summaryTable.sex"));
	//����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("unitreport.summaryTable.age"));
	//���֤����
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("unitreport.summaryTable.idCard"));
	//���ʱ��
	API_DTO_FIELD_DEFAULT(String, physicalDate, ZH_WORDS_GETTER("unitreport.summaryTable.physicalDate"));
	//������
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unitreport.summaryTable.physicalType"));
	//����ԭ��
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("unitreport.summaryTable.reason"));
	//������Ŀ
	API_DTO_FIELD_DEFAULT(String, checkProjectName, ZH_WORDS_GETTER("unitreport.summaryTable.checkProjectName"));
};

class ReviewPersonnelPageDTO : public PageDTO< ReviewPersonnelDTO::Wrapper>
{
	//�����ʼ��
	DTO_INIT(ReviewPersonnelPageDTO, PageDTO<ReviewPersonnelDTO::Wrapper>);
};
/*
* ���������ܱ�����ʵ��
*/

class ReviewResultsDTO : public oatpp::DTO
{
	//�����ʼ��
	DTO_INIT(ReviewResultsDTO, DTO);
	//���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unitreport.summaryTable.number"));
	//����
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("unitreport.summaryTable.personName"));
	//�ֻ���
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("unitreport.summaryTable.mobile"));
	//�Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("unitreport.summaryTable.sex"));
	//����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("unitreport.summaryTable.age"));
	//���֤����
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("unitreport.summaryTable.idCard"));
	//Σ������
	API_DTO_FIELD_DEFAULT(String, hazardFactorCode, ZH_WORDS_GETTER("unitreport.summaryTable.hazardFactorCode"));
	//����
	API_DTO_FIELD_DEFAULT(String, workTypeText, ZH_WORDS_GETTER("unitreport.summaryTable.hazardFactorCode"));
	//�Ӵ��к����䣨�꣩
	API_DTO_FIELD_DEFAULT(UInt32, ExposureToHarmfulWorkExperience, ZH_WORDS_GETTER("unitreport.summaryTable.ExposureToHarmfulWorkExperience"));
	//���ʱ��
	API_DTO_FIELD_DEFAULT(String, physicalDate, ZH_WORDS_GETTER("unitreport.summaryTable.physicalDate"));
	//�������
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unitreport.summaryTable.physicalType"));
	//���������
	API_DTO_FIELD_DEFAULT(String, checkRusult, ZH_WORDS_GETTER("unitreport.summaryTable.checkRusult"));
	//���鴦�����
	API_DTO_FIELD_DEFAULT(String, concludingObservations, ZH_WORDS_GETTER("unitreport.summaryTable.concludingObservations"));
};

class ReviewResultsPageDTO : public PageDTO< ReviewResultsDTO::Wrapper>
{
	//�����ʼ��
	DTO_INIT(ReviewResultsPageDTO, PageDTO<ReviewResultsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif
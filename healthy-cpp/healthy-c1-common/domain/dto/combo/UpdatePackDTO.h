#pragma once

#ifndef _UPDATEPACKDTO_H_
#define _UPDATEPACKDTO_H_

#include "../../GlobalInclude.h"
#include "./AddPackDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class UpdatePackDTO : public oatpp::DTO
{
	DTO_INIT(AddPackDTO, DTO);

	// ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("combo.field.id"));
	// �ײ�����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("combo.field.name"));
	// ����ͼƬ��ַ
	API_DTO_FIELD_DEFAULT(String, url, ZH_WORDS_GETTER("combo.field.url"));
	// �ײ�����
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("combo.field.type"));
	// ��ƴ
	API_DTO_FIELD_DEFAULT(String, simpleSpell, ZH_WORDS_GETTER("combo.field.simpleSpell"));
	// �����Ա�
	API_DTO_FIELD_DEFAULT(String, fitSex, ZH_WORDS_GETTER("combo.field.fitSex"));
	// �����
	API_DTO_FIELD_DEFAULT(Int32, orderNum, ZH_WORDS_GETTER("combo.field.orderNum"));
	// ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("combo.field.remark"));
	// ְҵ�׶�
	API_DTO_FIELD_DEFAULT(String, careerStage, ZH_WORDS_GETTER("combo.field.careerStage"));
	// Σ�����ر���
	API_DTO_FIELD_DEFAULT(String, hazardFactors, ZH_WORDS_GETTER("combo.field.hazardFactors"));
	// Σ�������ı�
	API_DTO_FIELD_DEFAULT(String, hazardFactorsText, ZH_WORDS_GETTER("combo.field.hazardFactorsText"));
	// ְҵ��
	API_DTO_FIELD_DEFAULT(String, occupationalDiseases, ZH_WORDS_GETTER("combo.field.occupationalDiseases"));
	// ְҵ����
	API_DTO_FIELD_DEFAULT(String, occupationalTaboo, ZH_WORDS_GETTER("combo.field.occupationalTaboo"));
	// ְҵ������
	API_DTO_FIELD_DEFAULT(String, occupationalDiseasesCode, ZH_WORDS_GETTER("combo.field.occupationalDiseasesCode"));
	// ְҵ���ɱ���
	API_DTO_FIELD_DEFAULT(String, occupationalTabooCode, ZH_WORDS_GETTER("combo.field.occupationalTabooCode"));
	// ��ϱ�׼
	API_DTO_FIELD_DEFAULT(String, diagnosticCriteria, ZH_WORDS_GETTER("combo.field.diagnosticCriteria"));
	// ֢״ѯ��
	API_DTO_FIELD_DEFAULT(String, symptomInquiry, ZH_WORDS_GETTER("combo.field.symptomInquiry"));

};

/**
 * ����һ���û���Ϣ��ҳ�������
 */
class UpdatePackPageDTO : public PageDTO<UpdatePackDTO::Wrapper>
{
	DTO_INIT(UpdatePackPageDTO, PageDTO<UpdatePackDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_UPDATEPACKDTO_H_

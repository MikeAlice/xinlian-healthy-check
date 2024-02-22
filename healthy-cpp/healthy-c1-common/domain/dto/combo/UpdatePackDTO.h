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
	// 套餐名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("combo.field.name"));
	// 封面图片地址
	API_DTO_FIELD_DEFAULT(String, url, ZH_WORDS_GETTER("combo.field.url"));
	// 套餐类型
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("combo.field.type"));
	// 简拼
	API_DTO_FIELD_DEFAULT(String, simpleSpell, ZH_WORDS_GETTER("combo.field.simpleSpell"));
	// 适用性别
	API_DTO_FIELD_DEFAULT(String, fitSex, ZH_WORDS_GETTER("combo.field.fitSex"));
	// 排序号
	API_DTO_FIELD_DEFAULT(Int32, orderNum, ZH_WORDS_GETTER("combo.field.orderNum"));
	// 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("combo.field.remark"));
	// 职业阶段
	API_DTO_FIELD_DEFAULT(String, careerStage, ZH_WORDS_GETTER("combo.field.careerStage"));
	// 危害因素编码
	API_DTO_FIELD_DEFAULT(String, hazardFactors, ZH_WORDS_GETTER("combo.field.hazardFactors"));
	// 危害因素文本
	API_DTO_FIELD_DEFAULT(String, hazardFactorsText, ZH_WORDS_GETTER("combo.field.hazardFactorsText"));
	// 职业病
	API_DTO_FIELD_DEFAULT(String, occupationalDiseases, ZH_WORDS_GETTER("combo.field.occupationalDiseases"));
	// 职业禁忌
	API_DTO_FIELD_DEFAULT(String, occupationalTaboo, ZH_WORDS_GETTER("combo.field.occupationalTaboo"));
	// 职业病编码
	API_DTO_FIELD_DEFAULT(String, occupationalDiseasesCode, ZH_WORDS_GETTER("combo.field.occupationalDiseasesCode"));
	// 职业禁忌编码
	API_DTO_FIELD_DEFAULT(String, occupationalTabooCode, ZH_WORDS_GETTER("combo.field.occupationalTabooCode"));
	// 诊断标准
	API_DTO_FIELD_DEFAULT(String, diagnosticCriteria, ZH_WORDS_GETTER("combo.field.diagnosticCriteria"));
	// 症状询问
	API_DTO_FIELD_DEFAULT(String, symptomInquiry, ZH_WORDS_GETTER("combo.field.symptomInquiry"));

};

/**
 * 定义一个用户信息分页传输对象
 */
class UpdatePackPageDTO : public PageDTO<UpdatePackDTO::Wrapper>
{
	DTO_INIT(UpdatePackPageDTO, PageDTO<UpdatePackDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_UPDATEPACKDTO_H_

#pragma once
#ifndef _TESTDETAILDTO_H_
#define _TESTDETAILDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class TestDetailDTO : public oatpp::DTO
{
	DTO_INIT(TestDetailDTO, DTO);
	//检测信息id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("test.field.id"));
	//单位id
	API_DTO_FIELD_DEFAULT(String, unitId, ZH_WORDS_GETTER("test.field.unit_id"));
	//职业有害因素编码
	API_DTO_FIELD_DEFAULT(String, hazardFactors, ZH_WORDS_GETTER("test.field.hazard_factors"));
	//职业有害因素名称
	API_DTO_FIELD_DEFAULT(String, hazardFactorsText, ZH_WORDS_GETTER("test.field.hazard_factors_text"));
	//其他有害因素名称
	API_DTO_FIELD_DEFAULT(String, otherHazardFactors, ZH_WORDS_GETTER("test.field.other_hazard_factors"));
	//在岗状态编码
	API_DTO_FIELD_DEFAULT(String, workStateCode, ZH_WORDS_GETTER("test.field.work_state_code"));
	//在岗状态
	API_DTO_FIELD_DEFAULT(String, workStateText, ZH_WORDS_GETTER("test.field.work_state_text"));
	//工种代码
	API_DTO_FIELD_DEFAULT(String, workTypeCode, ZH_WORDS_GETTER("test.field.work_type_code"));
	//工种名称
	API_DTO_FIELD_DEFAULT(String, workTypeText, ZH_WORDS_GETTER("test.field.work_type_text"));
	//其他工种名称
	API_DTO_FIELD_DEFAULT(String, workName, ZH_WORDS_GETTER("test.field.work_name"));
	//浓度（强度）范围
	API_DTO_FIELD_DEFAULT(String, strength, ZH_WORDS_GETTER("test.field.strength"));
	//检测时间
	API_DTO_FIELD_DEFAULT(String, testTime, ZH_WORDS_GETTER("test.field.test_time"));

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTDETAILDTO_H_
#ifndef _REPORTDTO_H_
#define _REPORTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * ʾ���������
 */
class ReportDTO : public oatpp::DTO
{
	DTO_INIT(ReportDTO, DTO);
	//������
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("uint.code"));
	//�������
	API_DTO_FIELD_DEFAULT(String, phyType, ZH_WORDS_GETTER("uint.phyType"));
	//��쵥λ
	API_DTO_FIELD_DEFAULT(String, phyUnit, ZH_WORDS_GETTER("uint.phyUnit"));
	//ί�е�λ
	API_DTO_FIELD_DEFAULT(String, enUnit, ZH_WORDS_GETTER("uint.enUnit"));
	//��������
	API_DTO_FIELD_DEFAULT(String, phyDate, ZH_WORDS_GETTER("uint.phyDate"));
	//�������
	API_DTO_FIELD_DEFAULT(Int32, phyNum, ZH_WORDS_GETTER("uint.phyNum"));
	//Σ������
	API_DTO_FIELD_DEFAULT(String, hazFactor, ZH_WORDS_GETTER("uint.hazFactor"));
	//�����Ŀ
	API_DTO_FIELD_DEFAULT(String, phyProj, ZH_WORDS_GETTER("uint.phyProj"));
	//��������
	API_DTO_FIELD_DEFAULT(String, evalBasis, ZH_WORDS_GETTER("uint.evalBasis"));
	//�����ۼ��������
	API_DTO_FIELD_DEFAULT(String, phyConclusion, ZH_WORDS_GETTER("uint.phyConclusion"));

	//���ص�ַ
	API_DTO_FIELD_DEFAULT(String, downloadAddr, ZH_WORDS_GETTER("uint.downloadAddr"));

};

#include OATPP_CODEGEN_END(DTO)
#endif 



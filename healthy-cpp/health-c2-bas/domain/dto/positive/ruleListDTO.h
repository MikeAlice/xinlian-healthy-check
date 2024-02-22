#ifndef _RULELIST_DTO_
#define _RULELIST_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ���������ݶ���ʵ��
 */
class ruleListDTO : public oatpp::DTO
{
	DTO_INIT(ruleListDTO, DTO);
	// Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("positive.rules.field.id"));
	// ��Ŀ����
	API_DTO_FIELD_DEFAULT(String, projectName, ZH_WORDS_GETTER("positive.rules.field.projectName"));
	// ����
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("positive.rules.field.type"));
	//����ֵ
	API_DTO_FIELD_DEFAULT(String, regularValue, ZH_WORDS_GETTER("positive.rules.field.regularValue"));
	// ���Թ���Id
	API_DTO_FIELD_DEFAULT(String, positiveResultsId, ZH_WORDS_GETTER("positive.rules.field.positiveResultsId"));
};

/**
 * ��ҳ�������
 */
class rulePageDTO : public PageDTO<ruleListDTO::Wrapper>
{
	DTO_INIT(rulePageDTO, PageDTO<ruleListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RULELIST_DTO_
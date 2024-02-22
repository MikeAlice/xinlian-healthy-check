#ifndef __DEATIL_QUERY__
#define __DEATIL_QUERY__

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ѯ���Խ����ϸʵ��
 */
class DeatilQuery : public oatpp::DTO
{
	DTO_INIT(DeatilQuery, DTO);
	//��ѯ����
	API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("deatil.field.type"));
	// ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("deatil.field.name"));
	// ��ƴ
	API_DTO_FIELD_DEFAULT(String, namePinYin, ZH_WORDS_GETTER("deatil.field.namePinYin"));
	// �Ƿ�����
	API_DTO_FIELD_DEFAULT(String, degree, ZH_WORDS_GETTER("deatil.field.degree"));
	//�Ƿ�����
	API_DTO_FIELD_DEFAULT(String, positive, ZH_WORDS_GETTER("deatil.field.positive"));
	//����
	API_DTO_FIELD_DEFAULT(String, sectionName, ZH_WORDS_GETTER("deatil.field.sectionName"));
	//ְҵ����
	API_DTO_FIELD_DEFAULT(String, advise, ZH_WORDS_GETTER("deatil.field.advise"));
	//��������
	API_DTO_FIELD_DEFAULT(String, healthKnowledge, ZH_WORDS_GETTER("deatil.field.healthKnowledge"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !__DEATIL_QUERY__
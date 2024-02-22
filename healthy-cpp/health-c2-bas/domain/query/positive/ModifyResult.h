#ifndef _MODIFYRESULT_H_
#define _MODIFYRESULT_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* �޸����Խ��
*/

class ModifyResult : public oatpp::DTO
{
    DTO_INIT(ModifyResult, DTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("modify.field.id");
	}
	
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
#endif // _MODIFYRESULT_H_

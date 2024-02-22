#ifndef _REPORTPREVIEMQUERY_QUERY_
#define	_REPORTPREVIEMQUERY_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* ����Ԥ��
*/
class ReportPreviewQuery :public oatpp::DTO
{
	DTO_INIT(ReportPreviewQuery, DTO);
	//�����ID
	DTO_FIELD(String, person_id);
	DTO_FIELD_INFO(person_id) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.personid");
	}
	//���������
	DTO_FIELD(String, person_name);
	DTO_FIELD_INFO(person_name) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.person_name");
	}
	//��ĿID
	DTO_FIELD(List<String>, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.code");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_REPORTPREVIEMQUERY_QUERY_


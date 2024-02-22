#ifndef _PERDEL_CONTROLLER_H_
#define _PERDEL_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class perdelController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(perdelController);
public:	// ����ӿ�

	// ����ɾ���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("questatistics.remove.summary"), removePersonList, Uint64JsonVO::Wrapper);
	// ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/questatistics/remove-personList", removePersonList, BODY_STRING(String, id), execRemovePerson(id));

private: // ����ӿ�ִ�к���
	Uint64JsonVO::Wrapper execRemovePerson(const string& id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PERDEL_CONTROLLER_H_

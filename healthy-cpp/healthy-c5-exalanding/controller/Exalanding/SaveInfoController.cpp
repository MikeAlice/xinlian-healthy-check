#include "stdafx.h"
#include "SaveInfoController.h"
#include "../../service/Exalanding/SaveInfoService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper SaveInfoController::execAddUserInfo(const SaveInfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->id || !dto->age || !dto->id_card || !dto->sex || !dto->person_name || !dto->mobile || !dto->is_marry || !dto->is_pass)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->id->empty() || dto->age < 0 || dto->id_card->empty() || dto->sex->empty() || dto->person_name->empty() || dto->mobile->empty() || dto->is_marry->empty() || dto->is_pass < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	SampleService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}
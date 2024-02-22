#include "stdafx.h"
#include "GroupPersonController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/Exalanding/GroupPersonService.h"

Uint64JsonVO::Wrapper GroupPersonController::execAddGroupPerson(const GroupPersonDTO::Wrapper& dto) {
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->testNum || !dto->personName)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->age < 0 || dto->personName->empty() || dto->sex->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	GroupPersonService service;
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
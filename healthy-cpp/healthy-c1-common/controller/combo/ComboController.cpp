#include "stdafx.h"
#include "ComboController.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper ComboController::execAddPack(const AddPackDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��

	// ����һ��Service
	AddPackService service;
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

Uint64JsonVO::Wrapper ComboController::execDelPack(const DelPackDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��

	// ����һ��Service
	DelPackService service;

	// ִ����������
	uint64_t id = service.removeData(dto);
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

Uint64JsonVO::Wrapper ComboController::execUpdatePack(const UpdatePackDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��

	// ����һ��Service
	UpdatePackService service;

	// ִ����������
	uint64_t id = service.modifyData(dto);
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

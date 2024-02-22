#include "stdafx.h"
#include "AddController.h"
#include "../../service/add/addService.h"

AddPageJsonVO::Wrapper AddController::execQueryAdd(const AddUnit::Wrapper& query)
{
	return {};
}

Uint64JsonVO::Wrapper AddController::execAddUnit(const AddUnitDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��

	// ����һ��Service
	addService service;
	// ִ����������
	uint64_t id = service.saveData(dto);

		jvo->success(UInt64(id));
	
	//��Ӧ���
	return jvo;
}

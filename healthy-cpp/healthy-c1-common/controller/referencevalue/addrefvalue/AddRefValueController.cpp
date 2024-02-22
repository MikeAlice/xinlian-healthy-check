#include "stdafx.h"
#include "AddRefValueController.h"
#include "service/referencevalue/addrefvalue/AddRefValueService.h"

Uint64JsonVO::Wrapper AddRefValueController::execAddRefValue(const AddRefValueDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->id || !dto->base_project_id || !dto->department_id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	/*if ()
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/

	// ����һ��Service
	AddRefValueService service;
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

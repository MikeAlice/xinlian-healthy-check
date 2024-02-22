
#include "addCritValueController.h"
#include "../../../domain/dto/database/CritValueDTO.h"
#include "../../../service/database/addcritvalue/AddCritValueService.h"




Uint64JsonVO::Wrapper AddCritValueController::execCriticalValue(const CritValueDTO::Wrapper & dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->level || !dto->type || !dto->intervalValue)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	/*if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/

	// ����һ��Service
	AddCritValueService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

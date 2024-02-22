#include "stdafx.h"
#include "criticalModifyController.h"
#include "../../service/critical/CriticalListService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper CriticalModifyController::execModifyCritical(const CriticalListDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//// ����У��
	//if (!dto->id)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	// ����һ��Service
	CriticalListService service;
	// ִ�������޸�
	int id = service.updateData(dto);
	if (id > 0) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}

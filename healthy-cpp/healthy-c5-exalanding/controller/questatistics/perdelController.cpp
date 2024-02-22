#include "stdafx.h"
#include "perdelController.h"
#include "../../service/questatistics/perdelService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../dao/questatistics/perdelDAO.h"

Uint64JsonVO::Wrapper perdelController::execRemovePerson(const string& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	UInt64 ID = std::stoi(id);
	// ����У��
	if (ID <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	perdelService service;
	// ����ɾ��
	bool result = service.removeData(id);
	if (result)
	{
		jvo->success(UInt64(std::stoi(id)));
	}
	else
	{
		jvo->fail(UInt64(std::stoi(id)));
	}
	return jvo;
}

#include "stdafx.h"
#include "ReferenceDelController.h"
#include "../../service/base/ReferenceDelService.h"
#include "../ApiDeclarativeServicesHelper.h"


Uint64JsonVO::Wrapper ReferenceDelController::execRemoveReference(const ReferenceDelDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	//UInt64 ID = std::atoi(((string)(id)).c_str());
	// ����У��
	if (!dto->id/*!ID || ID <= 0*/)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ReferenceDelService service;

	int id = service.removeData(dto);
	// ִ������ɾ��
	if (id>0) {
		jvo->success(id);
	}
	else
	{ 
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}


//Uint64JsonVO::Wrapper CriticalDeleteController::execDeleteCritical(const CriticalDeleteListDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	if (!dto->id)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	CriticalListService service;
//	// ִ������ɾ��
//	int id = service.removeData(dto);
//	if (id > 0) {
//		jvo->success(id);
//	}
//	else
//	{
//		jvo->fail(id);
//	}
//	// ��Ӧ���
//	return jvo;
//}
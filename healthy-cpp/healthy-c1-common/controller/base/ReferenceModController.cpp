
#include "stdafx.h"
#include "ReferenceModController.h"
#include "../../service/base/ReferenceModService.h"
#include "../ApiDeclarativeServicesHelper.h"


Uint64JsonVO::Wrapper ReferenceModController::execModifyReference(const ReferenceModDTO::Wrapper& modDto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//test
	UInt64 ID = std::atoi(((string)(modDto->id)).c_str());
	
	// ����У��
	if (!ID || ID <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//����һ��Service
	ReferenceModService service;
	// ִ�������޸�
	if (service.updateData(modDto)) {
		jvo->success(ID);
	}
	else
	{
		jvo->fail(ID);
	}
	// ��Ӧ���
	return jvo;
}
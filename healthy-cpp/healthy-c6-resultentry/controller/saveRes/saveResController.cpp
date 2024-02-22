#include "stdafx.h"
#include "controller/saveRes/saveResController.h"
#include "../../service/saveres/SaveResService.h"


Uint64JsonVO::Wrapper SaveResController::execAddDepartRes(const SaveResDTO::Wrapper& dto, const PayloadDTO& payload)
{
	
	string createId = payload.getId();
	
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->personId || !dto->groupItemId || !dto->officeId || !dto->checkDoc || !dto->checkDate)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->personId->empty() || dto->groupItemId->empty() || dto->officeId->empty() || dto->checkDoc->empty() || dto->checkDate->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	SaveResService service;
	// ���Ǹ���ʱ--����
	if (dto->isUpdate == 0)
	{
		// ִ����������
		uint64_t id = service.saveData(dto, createId);
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
	else {// ��ʱΪ����
		if (service.updateData(dto, createId)) {
			jvo->success(stoull(dto->updateId));
		}
		else
		{
			jvo->fail(stoull(dto->updateId));
		}
		// ��Ӧ���
		return jvo;
	}
	
}

Uint64JsonVO::Wrapper SaveResController::execAddRPProCheck(const RPProCheckDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->personId || !dto->groupItemId || !dto->officeId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->personId->empty() || dto->groupItemId->empty() || dto->officeId->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	SaveResService service;
	// ִ����������
	uint64_t id = service.saveRPProCheck(dto);
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

Uint64JsonVO::Wrapper SaveResController::execModifyWaiveCheck(const RPProCheckDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->personId || !dto->groupItemId || !dto->officeId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	SaveResService service;
	// ִ�������޸�
	if (service.updateRPProCheck(dto)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(1);
	}
	// ��Ӧ���
	return jvo;
}

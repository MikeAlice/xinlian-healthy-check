#include "stdafx.h"
#include "ModifyUnitController.h"
#include "uselib/validator/TestValidator.h"
#include "../../service/update-unit/ModifyUnitService.h"

//�޸ĵ�λ	�����ˣ�kzz
StringJsonVO::Wrapper ModifyUnitController::execModifyUnit(const UnitDetailDTO::Wrapper& dto, const PayloadDTO& payload)
{
	TestValidator validator;
	auto jvo = StringJsonVO::createShared();
	//����У��
	if ( !dto->uscc->empty() && !validator.is_valid_credit_code(dto->uscc)
		|| !dto->linkPhone1->empty() && !validator.is_valid_phone_number(dto->linkPhone1)
		|| !dto->linkPhone2->empty() && !validator.is_valid_phone_number(dto->linkPhone2)
		|| !dto->legalPhone->empty() && !validator.is_valid_phone_number(dto->legalPhone)
		|| !dto->safePhone->empty() && !validator.is_valid_phone_number(dto->safePhone)
		|| !dto->postalCode->empty() && !validator.is_valid_postal_code(dto->postalCode))
	{
		jvo->init("formatError", RS_PARAMS_INVALID);
		return jvo;
	}
	
	//����service��װ����Ӧ���
	ModifyUnitService service;
	std::string ret = service.updateUnit(dto, payload.getId());
	if (ret=="success") {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(ret);
	}
	// ������Ӧ���
	return jvo;
}


#include "stdafx.h"
#include "ModifyUnitController.h"
#include "uselib/validator/TestValidator.h"
#include "../../service/update-unit/ModifyUnitService.h"

//修改单位	负责人：kzz
StringJsonVO::Wrapper ModifyUnitController::execModifyUnit(const UnitDetailDTO::Wrapper& dto, const PayloadDTO& payload)
{
	TestValidator validator;
	auto jvo = StringJsonVO::createShared();
	//参数校验
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
	
	//调用service、装载响应结果
	ModifyUnitService service;
	std::string ret = service.updateUnit(dto, payload.getId());
	if (ret=="success") {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(ret);
	}
	// 返回响应结果
	return jvo;
}


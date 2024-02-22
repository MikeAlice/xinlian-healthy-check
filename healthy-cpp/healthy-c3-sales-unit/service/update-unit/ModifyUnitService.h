#pragma once
#include "../../domain/dto/update-unit/UnitDetailDTO.h"

#ifndef _MODIFYUNITSERVICE_H_
#define _MODIFYUNITSERVICE_H_

class ModifyUnitService
{
public:
	std::string updateUnit(const UnitDetailDTO::Wrapper& dto, const string& updateId);
};

#endif // !_MODIFYUNITSERVICE_H_

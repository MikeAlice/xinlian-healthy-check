#pragma once

#ifndef _UPDATEPACKSERVICE_H_
#define _UPDATEPACKSERVICE_H_
#include "domain/dto/combo/UpdatePackDTO.h"

class UpdatePackService
{
public:
	// ������� �����ˣ���è
	int modifyData(const UpdatePackDTO::Wrapper& dto);
};

#endif // _UPDATEPACKSERVICE_H_
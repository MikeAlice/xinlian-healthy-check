#pragma once

#ifndef _UPDATEPACKSERVICE_H_
#define _UPDATEPACKSERVICE_H_
#include "domain/dto/combo/UpdatePackDTO.h"

class UpdatePackService
{
public:
	// 添加数据 负责人：熊猫
	int modifyData(const UpdatePackDTO::Wrapper& dto);
};

#endif // _UPDATEPACKSERVICE_H_
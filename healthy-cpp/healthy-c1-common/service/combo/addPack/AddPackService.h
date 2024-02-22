#pragma once

#ifndef _ADDPACKSERVICE_H_
#define _ADDPACKSERVICE_H_
#include "domain/dto/combo/AddPackDTO.h"

class AddPackService
{
public:
	// 添加数据 负责人：熊猫
	uint64_t saveData(const AddPackDTO::Wrapper& dto);
};

#endif // _ADDPACKSERVICE_H_
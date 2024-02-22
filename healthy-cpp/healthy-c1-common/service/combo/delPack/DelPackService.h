#pragma once

#ifndef _DELPACKSERVICE_H_
#define _DELPACKSERVICE_H_
#include "domain/dto/combo/DelPackDTO.h"

class DelPackService
{
public:
	// 添加数据 负责人：熊猫
	int removeData(const DelPackDTO::Wrapper& dto);
};

#endif // _DELPACKSERVICE_H_
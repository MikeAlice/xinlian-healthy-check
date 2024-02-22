#pragma once
#include "../../domain/dto/saveres/SaveResDTO.h"
#include "../../../lib-common/include/SnowFlake.h"

#include "../../domain/dto/saveres/RPProCheckDTO.h"
#ifndef _SAVERES_SERVICE_
#define _SAVERES_SERVICE_



/*
* 保存结果服务实现
*/
class  SaveResService {
public:
	uint64_t saveData(const SaveResDTO::Wrapper& dto, const string createId);
	bool updateData(const SaveResDTO::Wrapper& dto, const string createId);

	uint64_t saveRPProCheck(const RPProCheckDTO::Wrapper& dto);
	bool updateRPProCheck(const RPProCheckDTO::Wrapper& dto);
};


#endif // !_SAVERES_SERVICE_



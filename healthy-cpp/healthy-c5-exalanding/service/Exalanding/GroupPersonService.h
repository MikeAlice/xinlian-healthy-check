#ifndef _GROUPPERSON_SERVICE_
#define _GROUPPERSON_SERVICE_
#include "domain/dto/Exalanding/GroupPersonDTO.h"
#include "domain/do/Exalanding/GroupPersonDO.h"
/**
 * 团检人员服务实现
 */
class GroupPersonService
{
public:
	// 保存数据
	uint64_t saveData(const GroupPersonDTO::Wrapper& dto);
};

#endif // !_GROUPPERSON_SERVICE_


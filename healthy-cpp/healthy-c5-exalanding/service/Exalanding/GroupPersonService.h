#ifndef _GROUPPERSON_SERVICE_
#define _GROUPPERSON_SERVICE_
#include "domain/dto/Exalanding/GroupPersonDTO.h"
#include "domain/do/Exalanding/GroupPersonDO.h"
/**
 * �ż���Ա����ʵ��
 */
class GroupPersonService
{
public:
	// ��������
	uint64_t saveData(const GroupPersonDTO::Wrapper& dto);
};

#endif // !_GROUPPERSON_SERVICE_


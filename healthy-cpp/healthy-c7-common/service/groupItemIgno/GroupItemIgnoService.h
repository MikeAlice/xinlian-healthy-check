#pragma once

#ifndef _GROUPITEMIGNO_SERVICE_
#define _GROUPITEMIGNO_SERVICE_

#include "domain/dto/groupItemIgno/GroupItemIgnoDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class GroupItemIgnoService
{
public:

	// �޸�����ignore_state = 2
	bool updateData(const GroupItemIgnoDTO::Wrapper& dto);
	
};

#endif // !_SAMPLE_SERVICE_


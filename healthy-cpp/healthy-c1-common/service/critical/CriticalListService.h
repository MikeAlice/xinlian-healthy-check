#pragma once

#ifndef _CRITICAL_LIST_SERVICE_
#define _CRITICAL_LIST_SERVICE_
#include <list>
#include "domain/vo/critical/CriticalModifyVO.h"
#include "domain/vo/critical/CriticalDeleteVO.h"
#include "domain/query/critical/CriticalQuery.h"
#include "domain/dto/critical/CriticalDeleteDTO.h"
#include "domain/dto/critical/CriticalModifyDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class CriticalListService
{
public:
	// �޸�����
	bool updateData(const CriticalListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(const CriticalDeleteListDTO::Wrapper& dto);
};

#endif 
#pragma once

#ifndef _DELPACKDAO_H_
#define _DELPACKDAO_H_
#include "BaseDAO.h"
#include "domain/do/combo/DelPackDO.h"

class DelPackDAO : public BaseDAO
{
public:
	// ɾ������	�����ˣ���è
	// ͨ��IDɾ������
	int deleteById(string id);
};
#endif // _ADDPACKDAO_H_
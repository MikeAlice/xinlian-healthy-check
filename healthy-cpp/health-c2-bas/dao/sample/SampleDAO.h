#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/sample/SampleDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class SampleDAO : public BaseDAO
{
public:
	// �޸�����
	int update(const SampleDO& uObj);
};
#endif // !_SAMPLE_DAO_

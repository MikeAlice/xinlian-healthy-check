#pragma once
#ifndef _SAVE_INFO_DAO_
#define _SAVE_INFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Exalanding/SaveInfoDO.h"
#include "../../domain/query/Exalanding/SaveInfoQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class SaveInfoDAO : public BaseDAO
{
public:
	// ��������
	uint64_t insert(const SaveInfoDO& iObj);
	
};
#endif // !_SAVE_INFO_DAO_
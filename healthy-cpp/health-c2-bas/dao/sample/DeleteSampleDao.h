#pragma once
#ifndef _DELETE_SAMPLE_DAO_
#define _DELETE_SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/sample/DeleteSampleDO.h"
//#include "../../domain/query/sample/DeleteSampleQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class DeleteSampleDAO : public BaseDAO
{
public:
	
	// ͨ��IDɾ������
	int deleteById(const string& id);
};
#endif // !_DELETESAMPLE_DAO_

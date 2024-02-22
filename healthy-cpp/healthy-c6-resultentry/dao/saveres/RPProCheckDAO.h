#pragma once
#ifndef _RPPROCHECK_DAO_
#define _RPPROCHECK_DAO_
#include"BaseDAO.h"
#include "../../domain/do/saveres/RPProCheckDO.h"


/**
* class InterroDAO
*/
class RPProCheckDAO : public BaseDAO {
public:
	//�����û���Ŀ���
	uint64_t insert(const RPProCheckDO& iObj);
	//�޸��û���Ŀ�������
	int update(const RPProCheckDO& uObj);
	
};

#endif // !_RPPROCHECK_DAO_

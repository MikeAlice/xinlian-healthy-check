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
	//插入用户项目检查
	uint64_t insert(const RPProCheckDO& iObj);
	//修改用户项目检查弃检
	int update(const RPProCheckDO& uObj);
	
};

#endif // !_RPPROCHECK_DAO_

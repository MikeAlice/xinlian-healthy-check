#pragma once
#ifndef _SAVERES_DAO_
#define _SAVERES_DAO_
#include"BaseDAO.h"
#include "../../domain/do/saveres/SaveResDO.h"


/**
* class InterroDAO
*/
class SaveResDAO : public BaseDAO {
public:
	//插入数据诊台结果
	uint64_t insert(const SaveResDO& iObj);
	//插入数据诊台结果明细
	uint64_t insertItem(const SaveResDO& iObj);
	//更新数据诊台结果
	int update(const SaveResDO& iObj);
	//更新数据诊台结果
	int updateItem(const SaveResDO& iObj);
};

#endif // !_SAVERES_DAO_

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
	//����������̨���
	uint64_t insert(const SaveResDO& iObj);
	//����������̨�����ϸ
	uint64_t insertItem(const SaveResDO& iObj);
	//����������̨���
	int update(const SaveResDO& iObj);
	//����������̨���
	int updateItem(const SaveResDO& iObj);
};

#endif // !_SAVERES_DAO_

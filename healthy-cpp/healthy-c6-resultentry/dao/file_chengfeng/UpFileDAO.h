#pragma once
#ifndef _UP_FILE_DAO_
#define _UP_FILE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/file_chengfeng/UpFileDO.h"
#include "../../domain/dto/file_chengfeng/UpFileDTO.h"

/**
 * 数据库操作实现
 */
class UpFileDAO : public BaseDAO
{
public:
	
	// 修改数据
	int update(const UpFileDO& uObj,const string download);
	
};
#endif // !_UP_FILE_DAO_

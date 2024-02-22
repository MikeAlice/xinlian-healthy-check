#pragma once
#ifndef _PRINTMORE_DAO_
#define _PRINTMORE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/printmore/PrintMoreDO.h"

/**
 * 示例表数据库操作实现
 */
class PrintMoreDAO : public BaseDAO
{
public:
	// 通过证书管理的id查询证书
	list<CertificateManageDO> selectById(uint64_t id);

	// 通过文件名称查询文档地址
	list<DocumentFileDO> selectByDocName(string name);
};
#endif // !_PRINTMORE_DAO_

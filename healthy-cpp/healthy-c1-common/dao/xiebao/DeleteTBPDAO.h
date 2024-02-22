#pragma once
#ifndef _DELETETBP_DAO_
#define _DELETETBP_DAO_
#include "BaseDAO.h"
#include "../../domain/do/xiebao/DeleteTBPDO.h"

/** 
 * 示例表数据库操作实现
 */
class DeleteTBPDAO : public BaseDAO
{
public:
    // 通过code删除数据
    int DeleteTBP(const DeleteTBPDO& uObj);
};
#endif // !_DELETETBP_DAO_
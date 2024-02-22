#pragma once
#ifndef _UpdateTBPDAO_H_
#define _UpdateTBPDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/xiebao/UpdateTBPDO.h"

/**
 * 示例表数据库操作实现
 */
class UpdateTBPDAO : public BaseDAO
{
public:
    // 通过code删除数据
    int UpdateTBP(const UpdateTBPDO& uObj);
};
#endif // !_UpdateTBPDAO_H_


#include "DeleteTBPService.h"
#include "stdafx.h"
#include "../../dao/xiebao/DeleteTBPDAO.h"
bool DeleteTBPService::DeleteTBP(const DeleteTBPDTO::Wrapper& dto)
{
    // 组装DO数据
    DeleteTBPDO data;
    data.setCode(dto->code.getValue(0));
    // 执行数据修改
    DeleteTBPDAO dao;
    return dao.DeleteTBP(data) == 1;
}

#include "DeleteTBPDAO.h"
#include "stdafx.h"
#include <sstream>

int DeleteTBPDAO::DeleteTBP(const DeleteTBPDO& uObj)
{
    string sql = "DELETE FROM `t_base_project` WHERE `code`=?";
    return sqlSession->executeUpdate(sql, "%s", to_string(uObj.getCode()));
}

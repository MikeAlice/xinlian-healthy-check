#pragma once
#ifndef _DELETETBP_DAO_
#define _DELETETBP_DAO_
#include "BaseDAO.h"
#include "../../domain/do/xiebao/DeleteTBPDO.h"

/** 
 * ʾ�������ݿ����ʵ��
 */
class DeleteTBPDAO : public BaseDAO
{
public:
    // ͨ��codeɾ������
    int DeleteTBP(const DeleteTBPDO& uObj);
};
#endif // !_DELETETBP_DAO_
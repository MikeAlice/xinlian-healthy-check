#pragma once
#ifndef _UpdateTBPDAO_H_
#define _UpdateTBPDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/xiebao/UpdateTBPDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class UpdateTBPDAO : public BaseDAO
{
public:
    // ͨ��codeɾ������
    int UpdateTBP(const UpdateTBPDO& uObj);
};
#endif // !_UpdateTBPDAO_H_


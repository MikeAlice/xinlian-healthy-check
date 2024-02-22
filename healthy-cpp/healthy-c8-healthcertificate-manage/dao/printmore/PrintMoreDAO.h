#pragma once
#ifndef _PRINTMORE_DAO_
#define _PRINTMORE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/printmore/PrintMoreDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class PrintMoreDAO : public BaseDAO
{
public:
	// ͨ��֤������id��ѯ֤��
	list<CertificateManageDO> selectById(uint64_t id);

	// ͨ���ļ����Ʋ�ѯ�ĵ���ַ
	list<DocumentFileDO> selectByDocName(string name);
};
#endif // !_PRINTMORE_DAO_

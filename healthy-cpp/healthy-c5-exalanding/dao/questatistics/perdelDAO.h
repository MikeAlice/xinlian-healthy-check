#ifndef _PERDELDAO_H_
#define _PERDELDAO_H_
#include "BaseDAO.h"

/**
 * ���ݿ����ʵ��
 */
class perdelDAO : public BaseDAO
{
public:
	// ͨ��idɾ�������Ա
	int deleteByPersonId(const string& id);
};


#endif // !_PERDELDAO_H_

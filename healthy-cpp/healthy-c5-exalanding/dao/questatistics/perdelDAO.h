#ifndef _PERDELDAO_H_
#define _PERDELDAO_H_
#include "BaseDAO.h"

/**
 * 数据库操作实现
 */
class perdelDAO : public BaseDAO
{
public:
	// 通过id删除体检人员
	int deleteByPersonId(const string& id);
};


#endif // !_PERDELDAO_H_

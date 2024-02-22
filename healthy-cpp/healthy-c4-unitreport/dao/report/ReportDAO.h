#ifndef _REPORTDAO_H_
#define _REPORTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/report/ReportDO.h"
#include "../../domain/query/report/ReportQuery.h"

/*
 * 示例表数据库操作实现
 */
class ReportDAO : public BaseDAO
{
public:
	// 通过Id查询数据
	list<ReportDO> selectById(const string& id);
};
#endif 



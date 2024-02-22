#ifndef _REPORTDAO_H_
#define _REPORTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/report/ReportDO.h"
#include "../../domain/query/report/ReportQuery.h"

/*
 * ʾ�������ݿ����ʵ��
 */
class ReportDAO : public BaseDAO
{
public:
	// ͨ��Id��ѯ����
	list<ReportDO> selectById(const string& id);
};
#endif 



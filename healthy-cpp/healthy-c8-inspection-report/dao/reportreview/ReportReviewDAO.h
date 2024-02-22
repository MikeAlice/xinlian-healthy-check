#ifndef _REPORTREVIEW_DAO_
#define _REPORTREVIEW_DAO_
#include "BaseDAO.h"
#include "../../domain/do/reportreview/ReportReviewDO.h"

/**
 * 审核从检报告数据库操作实现
 */
class ReportReviewDAO : public BaseDAO
{
public:
	// 修改数据
	int update(const ReportReviewDO& uObj);
};
#endif
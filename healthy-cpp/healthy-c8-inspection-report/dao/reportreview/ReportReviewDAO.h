#ifndef _REPORTREVIEW_DAO_
#define _REPORTREVIEW_DAO_
#include "BaseDAO.h"
#include "../../domain/do/reportreview/ReportReviewDO.h"

/**
 * ��˴Ӽ챨�����ݿ����ʵ��
 */
class ReportReviewDAO : public BaseDAO
{
public:
	// �޸�����
	int update(const ReportReviewDO& uObj);
};
#endif
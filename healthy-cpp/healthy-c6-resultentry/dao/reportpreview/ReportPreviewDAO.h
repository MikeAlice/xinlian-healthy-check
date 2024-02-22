#ifndef _REPORTPREVIEW_DAO_
#define _REPORTPREVIEW_DAO_
#include "BaseDAO.h"
#include"domain/do/reportpreview/ReportPreviewDO.h"
/*
* 报告预览操作实现
*/
class ReportPreviewDAO : public BaseDAO
{
public:
	//查询报告预览
	list<ReportPreviewDO> queryReportPreview(const string& person_id,const string& person_name);
	//个人症状查询
	list<T_symptomDO> queryT_symptom(const string& person_name,const string& code);

};
#endif // !_REPORTPREVIEW_DAO_

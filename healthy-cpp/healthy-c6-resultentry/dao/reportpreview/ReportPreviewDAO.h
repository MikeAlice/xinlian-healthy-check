#ifndef _REPORTPREVIEW_DAO_
#define _REPORTPREVIEW_DAO_
#include "BaseDAO.h"
#include"domain/do/reportpreview/ReportPreviewDO.h"
/*
* ����Ԥ������ʵ��
*/
class ReportPreviewDAO : public BaseDAO
{
public:
	//��ѯ����Ԥ��
	list<ReportPreviewDO> queryReportPreview(const string& person_id,const string& person_name);
	//����֢״��ѯ
	list<T_symptomDO> queryT_symptom(const string& person_name,const string& code);

};
#endif // !_REPORTPREVIEW_DAO_

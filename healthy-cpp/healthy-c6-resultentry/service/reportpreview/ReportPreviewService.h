#ifndef _REPORTPREVIEW_SERVICE_
#define _REPORTPREVIEW_SERVICE_
#include"domain/query/reportpreview/ReportPreviewQuery.h"
#include"domain/dto/reportpreview/ReportPreviewDTO.h"
/*
* ��������鿴����
*/
class ReportPreviewService
{
public:
	//����Ԥ���鿴
	oatpp::List<ReportPreviewViewDTO::Wrapper> reportview(const ReportPreviewQuery::Wrapper& qdto, const PayloadDTO& payload);
	//����֢״�鿴
	oatpp::List<T_symptomDTO::Wrapper> symptomview(const ReportPreviewQuery::Wrapper& qdto, const PayloadDTO& payload);
	};

#endif // !_REPORTPREVIEW_SERVICE_

#ifndef _REPORTPREVIEW_SERVICE_
#define _REPORTPREVIEW_SERVICE_
#include"domain/query/reportpreview/ReportPreviewQuery.h"
#include"domain/dto/reportpreview/ReportPreviewDTO.h"
/*
* 样本条码查看服务
*/
class ReportPreviewService
{
public:
	//报告预览查看
	oatpp::List<ReportPreviewViewDTO::Wrapper> reportview(const ReportPreviewQuery::Wrapper& qdto, const PayloadDTO& payload);
	//个人症状查看
	oatpp::List<T_symptomDTO::Wrapper> symptomview(const ReportPreviewQuery::Wrapper& qdto, const PayloadDTO& payload);
	};

#endif // !_REPORTPREVIEW_SERVICE_

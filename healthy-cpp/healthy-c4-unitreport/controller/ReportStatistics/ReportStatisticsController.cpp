#include "stdafx.h"
#include "ReportStatisticsController.h"
#include "../../service/ReportStatistics/ReportStatisticsService.h"
#include "../ApiDeclarativeServicesHelper.h"


PhysicalExaminationPersonnelPageJsonVO::Wrapper PhysicalExaminationPersonnelController::execQueryPhysicalExaminationPersonnel(const ReportStatisticsQuery::Wrapper& query)
{
	//����һ��Service
	PhysicalExaminationPersonnelService service;
	//��ѯ����
	auto result = service.listAll(query);
	//��Ӧ���
	auto jvo = PhysicalExaminationPersonnelPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ReviewPersonnelPageJsonVO::Wrapper ReviewPersonnelController::execQueryReviewPersonnel(const ReportStatisticsQuery::Wrapper& query)
{
	//����һ��Service
	ReviewPersonnelService service;
	//��ѯ����
	auto result = service.listAll(query);
	//��Ӧ���
	auto jvo = ReviewPersonnelPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ReviewResultsPageJsonVO::Wrapper ReviewResultsController::execQueryReviewResults(const ReportStatisticsQuery::Wrapper& query)
{
	//����һ��Service
	ReviewResultsService service;
	//��ѯ����
	auto result = service.listAll(query);
	//��Ӧ���
	auto jvo = ReviewResultsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

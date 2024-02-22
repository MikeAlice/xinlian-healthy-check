#include "stdafx.h"
#include "ReportStatisticsController.h"
#include "../../service/ReportStatistics/ReportStatisticsService.h"
#include "../ApiDeclarativeServicesHelper.h"


PhysicalExaminationPersonnelPageJsonVO::Wrapper PhysicalExaminationPersonnelController::execQueryPhysicalExaminationPersonnel(const ReportStatisticsQuery::Wrapper& query)
{
	//定义一个Service
	PhysicalExaminationPersonnelService service;
	//查询数据
	auto result = service.listAll(query);
	//响应结果
	auto jvo = PhysicalExaminationPersonnelPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ReviewPersonnelPageJsonVO::Wrapper ReviewPersonnelController::execQueryReviewPersonnel(const ReportStatisticsQuery::Wrapper& query)
{
	//定义一个Service
	ReviewPersonnelService service;
	//查询数据
	auto result = service.listAll(query);
	//响应结果
	auto jvo = ReviewPersonnelPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ReviewResultsPageJsonVO::Wrapper ReviewResultsController::execQueryReviewResults(const ReportStatisticsQuery::Wrapper& query)
{
	//定义一个Service
	ReviewResultsService service;
	//查询数据
	auto result = service.listAll(query);
	//响应结果
	auto jvo = ReviewResultsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

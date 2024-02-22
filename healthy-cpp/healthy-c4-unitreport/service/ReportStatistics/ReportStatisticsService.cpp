#include "stdafx.h"
#include "ReportStatisticsService.h"
#include "../../dao/ReportStatistics/ReportStatisticsDAO.h"

PhysicalExaminationPersonnelPageDTO::Wrapper PhysicalExaminationPersonnelService::listAll(const ReportStatisticsQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PhysicalExaminationPersonnelPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ReportStatisticsDAO dao;
	uint64_t count = dao.countPhysicalExaminationPersonnel(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<PhysicalExaminationPersonnelDO> result = dao.selectWithPhysicalExaminationPersonnelPage(query);

	// ��DOת����DTO
	for (PhysicalExaminationPersonnelDO sub : result)
	{
		auto dto = PhysicalExaminationPersonnelDTO::createShared();
		dto->id = sub.getId();
		dto->personName = sub.getPersonName();
		dto->mobile = sub.getMobile();
		dto->sex = sub.getSex();
		dto->age = sub.getAge();
		dto->idCard = sub.getIdCard();
		dto->department = sub.getDepartment();
		dto->physicalDate = sub.getPhysicalDate();
		dto->physicalType = sub.getPhysicalType();
		if (sub.getCheckRusult() == 0)//Ϊ0��ʾ���쳣
		{
			dto->status = ZH_WORDS_GETTER("unitreport.summaryTable.normal");
			dto->checkRusult = ZH_WORDS_GETTER("unitreport.summaryTable.noAbnormalConditions");
		}
		else if(sub.getCheckRusult() == 1 ) //Ϊ1��ʾ�����쳣
		{
			dto->status = ZH_WORDS_GETTER("unitreport.summaryTable.abnormal");
			dto->checkRusult = ZH_WORDS_GETTER("unitreport.summaryTable.otherAbnormalities");
		}
		else if(sub.getCheckRusult() == 2) //Ϊ2��ʾְҵ�쳣
		{
			dto->status = ZH_WORDS_GETTER("unitreport.summaryTable.abnormal");
			dto->checkRusult = ZH_WORDS_GETTER("unitreport.summaryTable.occupationalContraindications");
		}
		dto->concludingObservations = sub.getConcludingObservations();
		pages->addData(dto);
	}

	return pages;
}

ReviewPersonnelPageDTO::Wrapper ReviewPersonnelService::listAll(const ReportStatisticsQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ReviewPersonnelPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ReportStatisticsDAO dao;
	uint64_t count = dao.countReviewPersonnel(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ReviewPersonnelDO> result = dao.selectWithReviewPersonnelPage(query);

	// ��DOת����DTO
	for (ReviewPersonnelDO sub : result)
	{
		auto dto = ReviewPersonnelDTO::createShared();
		dto->id = sub.getId();
		dto->personName = sub.getPersonName();
		dto->mobile = sub.getMobile();
		dto->sex = sub.getSex();
		dto->age = sub.getAge();
		dto->idCard = sub.getIdCard();
		dto->physicalDate = sub.getPhysicalDate();
		dto->physicalType = sub.getPhysicalType();
		dto->reason = sub.getReason();
		dto->checkProjectName = sub.getCheckProjectName();
		pages->addData(dto);
	}

	return pages;
}

ReviewResultsPageDTO::Wrapper ReviewResultsService::listAll(const ReportStatisticsQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ReviewResultsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ReportStatisticsDAO dao;
	uint64_t count = dao.countReviewResults(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ReviewResultsDO> result = dao.selectWithReviewResultsPage(query);

	// ��DOת����DTO
	for (ReviewResultsDO sub : result)
	{
		auto dto = ReviewResultsDTO::createShared();
		dto->id = sub.getId();
		dto->personName = sub.getPersonName();
		dto->mobile = sub.getMobile();
		dto->sex = sub.getSex();
		dto->age = sub.getAge();
		dto->idCard = sub.getIdCard();
		dto->hazardFactorCode = sub.getHazardFactorCode();
		dto->workTypeText = sub.getWorkTypeText();
		dto->ExposureToHarmfulWorkExperience = sub.getExposureToHarmfulWorkExperience();
		dto->physicalDate = sub.getPhysicalDate();
		dto->physicalType = sub.getPhysicalType();
		dto->checkRusult = sub.getCheckRusult();
		dto->concludingObservations = sub.getConcludingObservations();
		pages->addData(dto);
	}

	return pages;
}

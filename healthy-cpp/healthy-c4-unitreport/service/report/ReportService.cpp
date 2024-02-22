#include "stdafx.h"
#include "ReportService.h"
#include "../../dao/report/ReportDAO.h"
#include "OtherService.h"

ReportDTO::Wrapper ReportService::listAll(const IDQuery::Wrapper& query)
{
	ReportDAO dao;
	ReportDO result = dao.selectById(query->id).front();
	// ½«DO×ª»»³ÉDTO
	auto dto = ReportDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, result, code, Code, phyType, PhyType, phyUnit, PhyUnit, enUnit, EnUnit, phyDate, PhyDate, phyNum, PhyNum, hazFactor, HazFactor, phyProj, PhyProj, evalBasis, EvalBasis, phyConclusion, PhyConclusion);
	TestPdf::testText();
	dto->downloadAddr = TestFastDfs::testDfsWithConf("D:\\Users\\Joey\\Desktop\\zero-one-healthy-check\\healthy-cpp\\out\\build\\x64-Debug\\healthy-c4-unitreport\\test-text.pdf");
	return dto;
}

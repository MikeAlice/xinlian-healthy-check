#include "stdafx.h"
#include "PreviewReportService.h"
#include "../../dao/previewreport/PreviewReportDAO.h"
#include "uselib/pdf/PreviewReportPdf.h"
#include "uselib/fastdfs/PreviewReportFastDfs.h"


PreviewReportDTO::Wrapper PreviewReportService::listId(const PreviewReportQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PreviewReportDTO::createShared();
	PreviewReportDAO dao;
	PreviewReportPdf pdf;
	PreviewReportFastDfs FastDfs;
	list<PreviewReportDO> result = dao.selectByName(query->personId);
	// ��DOת����DTO
	for (PreviewReportDO sub : result)
	{
		auto dto = PreviewReportDTO::createShared();
		pdf.PreviewText(sub);
		dto->href =  FastDfs.PreviewReportDfsWithConf("print_report.pdf");
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub);
		pages = dto;
	}
	return pages;
}


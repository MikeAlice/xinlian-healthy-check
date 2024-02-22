#include "ReportService.h"
#include "dao/ReportView/ReportDAO.h"
#include "uselib/pdf/InspectPDF.h"
#include "uselib/InspectFastDfs/InspectFastDfs.h"


ReportDTO::Wrapper ReportService::listId(const ReportQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ReportDTO::createShared();
	InspectPdf pdf;
	InspectFastDfs FastDfs;
	ReportDAO dao;
	list<ReportDO> result = dao.selectByName(query->personId);

	// ��DOת����DTO
	for (ReportDO sub : result)
	{

		auto dto = ReportDTO::createShared();
		pdf.ReportText(sub);
		dto->href = FastDfs.InspectDfsWithConf("report.pdf");
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub);
		pages = dto;
	}
	return pages;
}

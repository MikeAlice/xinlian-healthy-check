#include "stdafx.h"
#include <iostream>
#include "PreviewReportService.h"
#include "../../dao/previews/PreviewReportDAO.h"
#include "PdfComponent.h"
#include <uselib/fastdfs/TestFastDfs.h>

PreviewReportDTO::Wrapper PreviewReportService::listId(const PreviewReportQuery::Wrapper& query)
{
    auto dto = PreviewReportDTO::createShared();
    PreviewReportDAO dao;
    list<PreviewReportDO> result = dao.selectByName(query->persionId);

    // ���� PDF ʵ��
    PdfComponent pdfComponent;
    auto checkAndWrapText = [&](const std::string& text, float x, float y, HPDF_Page& page) {
        const int maxLineLength = 80;  // ����г���
        //std::string wrappedText;

        for (int i = 0; i < text.length(); i += maxLineLength) {
            std::string line = text.substr(i, maxLineLength);
            pdfComponent.drawText(line, x, y, page);
            y -= 15.0;  // ������һ�е�������
        }
    };
    // �������ݿ��ѯ������������ݵ� PDF
    for (const PreviewReportDO& report : result) {
        // ����һ����ҳ��
        HPDF_Page newPage = pdfComponent.getNewPage();

        // ����ҳ������
        HPDF_Page_SetFontAndSize(newPage, pdfComponent.getCnSFont("SimSun"), 12);

        // �������ݵ� PDF ҳ��
        // ������Ϣ
        pdfComponent.drawText(ZH_WORDS_GETTER("preview.field.persion") + ":", 50.0, 780.0, newPage);
        pdfComponent.drawText(ZH_WORDS_GETTER("report.field.name") + ":" + report.getPerson_name(), 50.0, 750.0, newPage);
        pdfComponent.drawText(ZH_WORDS_GETTER("report.field.sex") + ":" + report.getSex(), 200.0, 750.0, newPage);
        std::string age = to_string(report.getAge());
        pdfComponent.drawText(ZH_WORDS_GETTER("report.field.age") + ":" + age, 350.0, 750.0, newPage);
        pdfComponent.drawText(ZH_WORDS_GETTER("preview.field.idcard") + ":" + report.getId_card(), 50.0, 720.0, newPage);
        pdfComponent.drawText(ZH_WORDS_GETTER("preview.field.mobile") + ":" + report.getMobile(), 250.0, 720.0, newPage);
        pdfComponent.drawText(ZH_WORDS_GETTER("report.field.type") + ":" + report.getPhysical_type(), 50.0, 690.0, newPage);
        pdfComponent.drawText(ZH_WORDS_GETTER("preview.field.dept") + ":" + report.getDept(), 250.0, 690.0, newPage);
        // ���ƽ���
        pdfComponent.drawText(ZH_WORDS_GETTER("preview.field.conclusion") + ":", 50.0, 550.0, newPage);
        checkAndWrapText(report.getConclusion(), 50.0, 535.0, newPage);

        // ���ƴ������
        pdfComponent.drawText(ZH_WORDS_GETTER("preview.field.handleopinion") + ":", 50, 300.0, newPage);
        checkAndWrapText(report.getHandle_opinion(), 50, 285.0, newPage);
        // �������ҽ������鵥λ������
        pdfComponent.drawText(ZH_WORDS_GETTER("preview.field.inspection_doctor") + ":" + report.getInspection_doctor(), 400, 50.0, newPage);
        pdfComponent.drawText(ZH_WORDS_GETTER("preview.field.diagnostic_unit") + ":" + report.getDiagnostic_unit(), 400, 30.0, newPage);
        pdfComponent.drawText(report.getInspection_date(), 400.0, 10.0, newPage);
        
    }
    // ���浱ǰҳ��
    pdfComponent.saveDocToFile("output_report.pdf");
    dto->pdfaddress = PreviewReportFastDfs::pdfDfsWithConf("output_report.pdf");

    return dto;
}

#include "stdafx.h"
#include "PreviewReportPdf.h"
#include <iostream>
#include "PdfComponent.h"
#include "ServerInfo.h"

void PreviewReportPdf::PreviewText(const PreviewReportDO& Do)
{
   
    // ���� PDF ʵ��
    PdfComponent pdfComponent;
    // ����һ����ҳ��
    HPDF_Page newPage = pdfComponent.getNewPage();

    // ����ҳ������
    HPDF_Page_SetFontAndSize(newPage, pdfComponent.getCnSFont("SimSun"), 12);

    // �������ݵ� PDF ҳ��
    pdfComponent.drawText(ZH_WORDS_GETTER("pdf.name") + ": " + Do.getName(), 50.0, 780.0, newPage);
    pdfComponent.drawText(ZH_WORDS_GETTER("pdf.inspectionDate") + ": " + Do.getInspectionDate(), 50.0, 750.0, newPage);
    pdfComponent.drawText(ZH_WORDS_GETTER("pdf.sex") + ": " + Do.getSex(), 200.0, 750.0, newPage);
    std::string age = to_string(Do.getAge());
    pdfComponent.drawText(ZH_WORDS_GETTER("pdf.age") + ": " + age, 350.0, 750.0, newPage);
    pdfComponent.drawText(ZH_WORDS_GETTER("pdf.idCard") + ": " + Do.getIdCard(), 50.0, 720.0, newPage);
    pdfComponent.drawText(ZH_WORDS_GETTER("pdf.mobile") + ": " + Do.getMobile(), 250.0, 720.0, newPage);
    pdfComponent.drawText(ZH_WORDS_GETTER("pdf.physicalType") + ": " + Do.getPhysicalType(), 50.0, 690.0, newPage);
    pdfComponent.drawText(ZH_WORDS_GETTER("pdf.dept") + ": " + Do.getDept(), 250.0, 690.0, newPage);
    pdfComponent.drawText(ZH_WORDS_GETTER("pdf.conclusion") + ": ", 50.0, 550.0, newPage);
    pdfComponent.drawText(Do.getConclusion(), 74.0, 530.0, newPage);
    pdfComponent.drawText(ZH_WORDS_GETTER("pdf.handleOpinion") + ": " , 50.0, 300.0, newPage);
    pdfComponent.drawText(Do.getHandleOpinion(), 74.0, 280.0, newPage);
    pdfComponent.drawText(ZH_WORDS_GETTER("pdf.inspectionDoctor") + ": " + Do.getInspectionDoctor(), 400.0, 50.0, newPage);
    pdfComponent.drawText(ZH_WORDS_GETTER("pdf.inspectionDate") + ": " + Do.getInspectionDate(), 400.0, 30.0, newPage);
    pdfComponent.drawText(ZH_WORDS_GETTER("pdf.diagnosticUnit") + ": " + Do.getDiagnosticUnit(), 400.0, 10.0, newPage);

    // ���浱ǰҳ��
    pdfComponent.saveDocToFile("print_report.pdf");
}
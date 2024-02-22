/*
 Copyright Zero One Star. All rights reserved.

 @Author: DY
 @Date: 2023/12/29 11:30:58

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "InspectPDF.h"
#include <iostream>
#include "PdfComponent.h"
#include "ServerInfo.h"





void InspectPdf::ReportText(const ReportDO& Do)
{
	// 创建 PDF 实例
	PdfComponent pdfComponent;
	// 创建一个新页面
	HPDF_Page newPage = pdfComponent.getNewPage();

	// 设置页面字体
	HPDF_Page_SetFontAndSize(newPage, pdfComponent.getCnSFont("SimSun"), 12);

	// 绘制数据到 PDF 页面
	pdfComponent.drawText(ZH_WORDS_GETTER("pdf.name") + ": " + Do.getName(), 50.0, 780.0, newPage);
	pdfComponent.drawText(ZH_WORDS_GETTER("pdf.inspectionDate") + ": " + Do.getInspectionDate(), 50.0, 750.0, newPage);
	pdfComponent.drawText(ZH_WORDS_GETTER("pdf.sex") + ": " + Do.getSex(), 250.0, 750.0, newPage);
	std::string age = to_string(Do.getAge());
	pdfComponent.drawText(ZH_WORDS_GETTER("pdf.age") + ": " + age, 350.0, 750.0, newPage);
	pdfComponent.drawText(ZH_WORDS_GETTER("pdf.idCard") + ": " + Do.getIdCard(), 50.0, 720.0, newPage);
	pdfComponent.drawText(ZH_WORDS_GETTER("pdf.mobile") + ": " + Do.getMobile(), 250.0, 720.0, newPage);
	pdfComponent.drawText(ZH_WORDS_GETTER("pdf.physicalType") + ": " + Do.getPhysicalType(), 50.0, 690.0, newPage);
	pdfComponent.drawText(ZH_WORDS_GETTER("pdf.dept") + ": " + Do.getDept(), 250.0, 690.0, newPage);
	pdfComponent.drawText(ZH_WORDS_GETTER("pdf.conclusion") + ": ", 50.0, 550.0, newPage);
	pdfComponent.drawText(Do.getConclusion(), 74.0, 530.0, newPage);
	pdfComponent.drawText(ZH_WORDS_GETTER("pdf.handleOpinion") + ": ", 50.0, 300.0, newPage);
	pdfComponent.drawText(Do.getHandleOpinion(), 74.0, 280.0, newPage);
	pdfComponent.drawText(ZH_WORDS_GETTER("pdf.inspectionDoctor") + ": " + Do.getInspectionDoctor(), 400.0, 50.0, newPage);
	pdfComponent.drawText(ZH_WORDS_GETTER("pdf.inspectionDate") + ": " + Do.getInspectionDate(), 400.0, 30.0, newPage);
	pdfComponent.drawText(ZH_WORDS_GETTER("pdf.diagnosticUnit") + ": " + Do.getDiagnosticUnit(), 400.0, 10.0, newPage);

	// 保存当前页面
	pdfComponent.saveDocToFile("report.pdf");
}


void InspectPdf::testText()
{
	PdfComponent pdf;
	// 创建一个页面
	HPDF_Page newPage = pdf.getNewPage();
	// 设置页面字体
	HPDF_Page_SetFontAndSize(newPage, pdf.getCnSFont("SimSun"), 20);
	// 绘制字体
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.title"), HPDF_Page_GetHeight(newPage) - 20);
	pdf.drawTextCenter(ZH_WORDS_GETTER("pdf.content"));
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.foot"), 20);
	// 保存到文件
	pdf.saveDocToFile("test-text.pdf");
}
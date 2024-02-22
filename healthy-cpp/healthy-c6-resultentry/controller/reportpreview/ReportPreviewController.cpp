#include "stdafx.h"
#include "ReportPreviewController.h"
#include"service/reportpreview/ReportPreviewService.h"
#include"dldlib/pdf/Pdf.h"
#include"dldlib/fastdfs/FastDfs.h"

StringJsonVO::Wrapper ReportPreviewController::execQueryReportPreview(const ReportPreviewQuery::Wrapper& qdto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (!qdto->person_id||!qdto->person_name||!qdto->code) {
		 jvo->fail(u8"����Ϊ��");
		 return jvo;
	}
	// ����һ��Service
	ReportPreviewService service;
	// ��ѯ����
	auto result1 = service.reportview(qdto, payload);
	auto result2 = service.symptomview(qdto,payload );
	if (result1->empty() || result2->empty()) {
		jvo->fail(u8"���Ҳ�����Ӧ����");
		return jvo;
	}
	//����PDF 
	string filename = "report.pdf";
	BarcodesPdf pdf;
	if (pdf.reportTpl(result1, result2, filename)==false) {
		jvo->fail(u8"pdf����ʧ��");
		return jvo;
	}
	BarcodesFastDfs fdfs;
	string downpath = fdfs.barcodesDfs(filename);
	if (downpath=="") {
		jvo->fail(u8"�ϴ�ʧ��");
		return jvo;
	}
	// ��Ӧ���
	jvo->success(downpath);
	return jvo;
}

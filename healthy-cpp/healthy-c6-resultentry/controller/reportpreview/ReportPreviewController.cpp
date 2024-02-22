#include "stdafx.h"
#include "ReportPreviewController.h"
#include"service/reportpreview/ReportPreviewService.h"
#include"dldlib/pdf/Pdf.h"
#include"dldlib/fastdfs/FastDfs.h"

StringJsonVO::Wrapper ReportPreviewController::execQueryReportPreview(const ReportPreviewQuery::Wrapper& qdto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (!qdto->person_id||!qdto->person_name||!qdto->code) {
		 jvo->fail(u8"数据为空");
		 return jvo;
	}
	// 定义一个Service
	ReportPreviewService service;
	// 查询数据
	auto result1 = service.reportview(qdto, payload);
	auto result2 = service.symptomview(qdto,payload );
	if (result1->empty() || result2->empty()) {
		jvo->fail(u8"查找不到对应数据");
		return jvo;
	}
	//调用PDF 
	string filename = "report.pdf";
	BarcodesPdf pdf;
	if (pdf.reportTpl(result1, result2, filename)==false) {
		jvo->fail(u8"pdf保存失败");
		return jvo;
	}
	BarcodesFastDfs fdfs;
	string downpath = fdfs.barcodesDfs(filename);
	if (downpath=="") {
		jvo->fail(u8"上传失败");
		return jvo;
	}
	// 响应结果
	jvo->success(downpath);
	return jvo;
}

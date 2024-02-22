#include "stdafx.h"
#include"SampleBarcodesBiewController.h"
#include"service/samplebarcodesview/SampleBarcodesViewService.h"
#include"dldlib/pdf/Pdf.h"
#include"dldlib/fastdfs/FastDfs.h"

StringJsonVO::Wrapper SampleBarcodesViewController::execQuerySampleBarcodesView(const SampleBarcodesViewQuery::Wrapper& qdto,const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (!qdto->person_id || !qdto->group_item_id || !qdto->type) {
		jvo->fail(u8"数据为空");
		return jvo;
	}
	// 定义一个Service
	SampleBarcodesViewServer service;
	// 查询数据
	auto result = service.barcodesview(qdto, payload);
	//调用PDF
	string filename = "barcodes.pdf";
	BarcodesPdf pdf;
	if (pdf.barcodesTpl(result, filename)==false) {
		jvo->fail(u8"pdf保存失败");
		return jvo;
	}
	BarcodesFastDfs fdfs;
	string downpath=fdfs.barcodesDfs(filename);
	if (downpath == "") {
		jvo->fail(u8"上传失败");
		return jvo;
	}
	// 响应结果
	jvo->success(downpath);
	return jvo;
}

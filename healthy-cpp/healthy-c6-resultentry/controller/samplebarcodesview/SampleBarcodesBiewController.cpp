#include "stdafx.h"
#include"SampleBarcodesBiewController.h"
#include"service/samplebarcodesview/SampleBarcodesViewService.h"
#include"dldlib/pdf/Pdf.h"
#include"dldlib/fastdfs/FastDfs.h"

StringJsonVO::Wrapper SampleBarcodesViewController::execQuerySampleBarcodesView(const SampleBarcodesViewQuery::Wrapper& qdto,const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (!qdto->person_id || !qdto->group_item_id || !qdto->type) {
		jvo->fail(u8"����Ϊ��");
		return jvo;
	}
	// ����һ��Service
	SampleBarcodesViewServer service;
	// ��ѯ����
	auto result = service.barcodesview(qdto, payload);
	//����PDF
	string filename = "barcodes.pdf";
	BarcodesPdf pdf;
	if (pdf.barcodesTpl(result, filename)==false) {
		jvo->fail(u8"pdf����ʧ��");
		return jvo;
	}
	BarcodesFastDfs fdfs;
	string downpath=fdfs.barcodesDfs(filename);
	if (downpath == "") {
		jvo->fail(u8"�ϴ�ʧ��");
		return jvo;
	}
	// ��Ӧ���
	jvo->success(downpath);
	return jvo;
}

#include "stdafx.h"
#include "PrintMoreService.h"
#include "uselib/fastdfs/UseFastDfs.h"
#include "../../dao/printmore/PrintMoreDAO.h"
#include <iostream>

string PrintMoreService::downloadPrintMore(const uint64_t& id)
{
	PrintMoreDAO dao;

	// 判断id是否存在
	list<CertificateManageDO> sub = dao.selectById(id);
	if (sub.size() == 0) {
		return "Error: id-" + to_string(id) + " doesn't exist";
	}

	string medical_ccertificat_id = "";
	// 判断是否上传，上传了就获取健康证上传id
	if ((*sub.begin()).getIs_upload() == "1") {
		medical_ccertificat_id = (*sub.begin()).getMedical_certificate_id();
	}
	else {
		return "Error: id-" + to_string(id) + " health certificate has not been uploaded";
	}

	// 文件名  "healthcertificate-上传id.pdf"
	string certificate_name = "healthcertificate-" + medical_ccertificat_id + ".pdf";
	// 根据文件名获得fastdfs下载url
	list<DocumentFileDO> docs = dao.selectByDocName(certificate_name);

	if (docs.size() == 0) {
		return "Error: " + certificate_name + " doesn't exist";
	}

	string url = docs.begin()->getUrl();
	// 下载到服务器用于打印
	UseFastDfs::downloadFile(url);
	return url;
}
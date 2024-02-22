#include "stdafx.h"
#include "PrintMoreService.h"
#include "uselib/fastdfs/UseFastDfs.h"
#include "../../dao/printmore/PrintMoreDAO.h"
#include <iostream>

string PrintMoreService::downloadPrintMore(const uint64_t& id)
{
	PrintMoreDAO dao;

	// �ж�id�Ƿ����
	list<CertificateManageDO> sub = dao.selectById(id);
	if (sub.size() == 0) {
		return "Error: id-" + to_string(id) + " doesn't exist";
	}

	string medical_ccertificat_id = "";
	// �ж��Ƿ��ϴ����ϴ��˾ͻ�ȡ����֤�ϴ�id
	if ((*sub.begin()).getIs_upload() == "1") {
		medical_ccertificat_id = (*sub.begin()).getMedical_certificate_id();
	}
	else {
		return "Error: id-" + to_string(id) + " health certificate has not been uploaded";
	}

	// �ļ���  "healthcertificate-�ϴ�id.pdf"
	string certificate_name = "healthcertificate-" + medical_ccertificat_id + ".pdf";
	// �����ļ������fastdfs����url
	list<DocumentFileDO> docs = dao.selectByDocName(certificate_name);

	if (docs.size() == 0) {
		return "Error: " + certificate_name + " doesn't exist";
	}

	string url = docs.begin()->getUrl();
	// ���ص����������ڴ�ӡ
	UseFastDfs::downloadFile(url);
	return url;
}
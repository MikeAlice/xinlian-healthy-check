#pragma once
#ifndef _PRINTMORE_DO_
#define _PRINTMORE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class CertificateManageDO
{
	// ����
	CC_SYNTHESIZE(uint64_t, id, Id);
	// �Ƿ��ϴ�
	CC_SYNTHESIZE(string, is_upload, Is_upload);
	// ����֤�ϴ�id
	CC_SYNTHESIZE(string, medical_certificate_id, Medical_certificate_id);
public:
	CertificateManageDO() {
		id = 0;
		is_upload = "";
		medical_certificate_id = "";
	}
};

class DocumentFileDO {
	// �ļ���ַ
	CC_SYNTHESIZE(string, url, Url);
public:
	DocumentFileDO() {
		url = "";
	}
};

#endif // !_PRINTMORE_DO_
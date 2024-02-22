#pragma once
#ifndef _PRINTMORE_DO_
#define _PRINTMORE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class CertificateManageDO
{
	// 主键
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 是否上传
	CC_SYNTHESIZE(string, is_upload, Is_upload);
	// 健康证上传id
	CC_SYNTHESIZE(string, medical_certificate_id, Medical_certificate_id);
public:
	CertificateManageDO() {
		id = 0;
		is_upload = "";
		medical_certificate_id = "";
	}
};

class DocumentFileDO {
	// 文件地址
	CC_SYNTHESIZE(string, url, Url);
public:
	DocumentFileDO() {
		url = "";
	}
};

#endif // !_PRINTMORE_DO_
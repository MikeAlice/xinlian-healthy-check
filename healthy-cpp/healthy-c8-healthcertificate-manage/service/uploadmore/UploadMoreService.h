#pragma once
#ifndef _UPLOADMORE_SERVICE_
#define _UPLOADMORE_SERVICE_
#include "domain/dto/uploadmore/UploadMoreDTO.h"

/**
 * ����֤��������ʵ��
 */
class UploadMoreService
{
public:
	// ͨ����Աid�����ϴ�����֤
	UploadMoreDTO::Wrapper  UploadHealthcertificate(const string& personId);

};

#endif 

